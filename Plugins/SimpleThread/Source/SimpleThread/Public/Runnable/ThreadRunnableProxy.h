#pragma once

#include "CoreMinimal.h"
//引入Runnable的
#include "HAL/Runnable.h"
//引入自定义的接口函数
#include "Interface/ProxyInterface.h"

//struct FPlatformProcess;
class FRunnableThread;

class FThreadRunnable : public FRunnable , public IThreadProxy
{
public:
	//添加构造函数
	FThreadRunnable();

	//添加析构函数
	virtual ~FThreadRunnable();

	//重写创建线程安全函数
	virtual void CreateSafeThread();

	//重写挂起函数
	virtual void SuspendThread();

	//重写唤醒函数
	virtual void WakeupThread();

private:
	//重写Runnable的初始化函数
	virtual bool Init() ;

	//重写Runabble的Run函数
	virtual uint32 Run() ;

	//重写Runnable的Stop函数
	virtual void Stop() ;

	//重写Runnable的Exit函数
	virtual void Exit() ;

private:
	//加入布尔变量判断当前线程是否执行
	bool bRun;

	//是否挂起线程
	bool bSuspend;

	//声明一个线程变量
	FRunnableThread* Thread;

	//声明线程名变量
	FName RunnableName;

	//声明线程事件变量 , 挂起线程使用
	FEvent* ThreadEvent;

	//线程计数
	static int32 ThreadCount;
};