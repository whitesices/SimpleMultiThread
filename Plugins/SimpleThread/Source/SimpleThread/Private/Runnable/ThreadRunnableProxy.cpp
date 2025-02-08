#include "Runnable/ThreadRunnableProxy.h"

//引入相应的头文件
#include "HAL/RunnableThread.h"
//#if PLATFORM_WINDOWS
//#include "Windows/WindowsPlatformProcess.h"
//#else if PLATFORM_ANDROID
// #include "Android/AndroidPlatformProcess.h"
//#endif


//初始化
int32 FThreadRunnable::ThreadCount = 0;

FThreadRunnable::FThreadRunnable():IThreadProxy(),bRun(false),bSuspend(false),Thread(nullptr),ThreadEvent( FPlatformProcess::GetSynchEventFromPool() )
{
}

FThreadRunnable::~FThreadRunnable()
{
	//释放当前的事件对象
	FPlatformProcess::ReturnSynchEventToPool(ThreadEvent);

	//线程置空
	if (Thread != NULL)
	{

	}
}

void FThreadRunnable::CreateSafeThread()
{
	//线程名赋值
	RunnableName = *(TEXT("SimpleThread-") + FString::Printf(TEXT("%i"), ThreadCount));

	//创建线程
	Thread = FRunnableThread::Create(this,*RunnableName.ToString(), 0, TPri_BelowNormal);

	//创建计数自增
	ThreadCount++;
}

void FThreadRunnable::SuspendThread()
{
	bSuspend = true;
}

void FThreadRunnable::WakeupThread()
{
	bSuspend = false;
	ThreadEvent->Trigger();
}

bool FThreadRunnable::Init()
{
	//判断当前平台是否支持多线程
	if (!FPlatformProcess::SupportsMultithreading())
	{
		bRun = false;
	}
	else
	{
		bRun = true;
	}


	return bRun;
}

uint32 FThreadRunnable::Run()
{

	//判断是否可以运行在判断是否可以挂起
	while (bRun)
	{
		if (bSuspend)
		{
			ThreadEvent->Wait();//挂起线程
		}

		//执行业务逻辑

		//判断当前代理是否被绑定
		if (ThreadDelegate.IsBound())
		{
			ThreadDelegate.Execute();
		}
		else
		{
			ThreadLambda();
		}
		
		
	}

	return 0;
}

void FThreadRunnable::Stop()
{

}

void FThreadRunnable::Exit()
{

	bRun = false;
}
