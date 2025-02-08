#include "ThreadManager.h"
//#include "Runnable/ThreadRunnableProxy.h"
//初始化
TSharedPtr<FThreadManagement> FThreadManagement::ThreadManagement = nullptr;

TSharedRef<FThreadManagement> FThreadManagement::Get()
{
	//判断线程池对象是否有效
	if (!ThreadManagement.IsValid())
	{
		//创建共享指针
		ThreadManagement = MakeShareable(new FThreadManagement);
	}

	return ThreadManagement.ToSharedRef();
}

void FThreadManagement::Destroy()
{
	//判断当前的线程对象是否有效
	if (ThreadManagement.IsValid())
	{
		//置空
		ThreadManagement = nullptr;
	}
}

//FThreadHandle FThreadManagement::CreateThread(const FThreadLambda& ThreadLamada)
//{
//	//FThreadRunnable* TR = nullptr;
//	TSharedPtr<IThreadProxy> ThreadProxy = MakeShareable(new FThreadRunnable);
//	ThreadProxy->GetThreadLambda() = ThreadLamada;
//	//调用更新线程池的方法
//	return UpdateThreadPool(ThreadProxy);
//}

FThreadHandle FThreadManagement::UpdateThreadPool(TSharedPtr<IThreadProxy> ThreadProxy)
{
	ThreadProxy->CreateSafeThread();

	//池化线程
	Pool.Add(ThreadProxy);

	//返回线程句柄
	return ThreadProxy->GetThreadHandle();
}
