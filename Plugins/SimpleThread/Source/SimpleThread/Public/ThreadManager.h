//线程管理设置为一个单例
//1.创建线程 2.查看线程的进度
//单例的标配 一个get 一个Destroy 一个静态变量
#pragma once

#include "CoreMinimal.h"
//引入自定义的接口函数
//#include "Interface/ProxyInterface.h"
//引入RunnableThread
#include "Runnable/ThreadRunnableProxy.h"
//#include "Core/SimpleThreadType.h"


class SIMPLETHREAD_API FThreadManagement : public TSharedFromThis<FThreadManagement>
{
public:
	//声明Get方法
	static TSharedRef<FThreadManagement> Get();

	//声明Destroy方法
	static void Destroy();

public:
	//添加模板方法
	template<class UserClass , typename... VarTypes>
	FThreadHandle CreateThreadRaw(UserClass* TargetClass, typename TMemFunPtrType<false, UserClass, void(VarTypes...)>::Type InMethod, VarTypes... Vars)
	{
		TSharedPtr<IThreadProxy> ThreadProxy = MakeShareable(new FThreadRunnable);
		ThreadProxy->GetThreadDelegate().BindRaw(TargetClass, InMethod, Vars ..);

		//调用更新线程池的方法
		return UpdateThreadPool(ThreadProxy);
	};
	

	//声明创建线程方法
	/*FThreadHandle CreateThread( const FThreadLambda &ThreadLamada);*/

protected:
	//更新线程池
	FThreadHandle UpdateThreadPool(TSharedPtr<IThreadProxy> ThreadProxy);

private:
	//建立线程池
	TArray<TSharedPtr<IThreadProxy>> Pool;

private:
	//声明一个静态的共享指针的Manager
	static TSharedPtr<FThreadManagement> ThreadManagement;
};

////实现创建线程
//template<class UserClass, typename ...VarTypes>
//inline FThreadHandle FThreadManagement::CreateThreadRaw(UserClass* TargetClass, typename TMemFunPtrType<false, UserClass, void(VarTypes...)>::Type InMethod, VarTypes ...Vars)
//{
//	TSharedPtr<IThreadProxy> ThreadProxy = MakeShareable(new FThreadRunnable);
//	ThreadProxy->GetThreadDelegate().BindRaw(TargetClass, InMethod, Vars ..);
//
//	//调用更新线程池的方法
//	return UpdateThreadPool(ThreadProxy);
//};
