// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Core/SimpleThreadType.h"

class SIMPLETHREAD_API IThreadProxy : public TSharedFromThis<IThreadProxy>
{
public:
	IThreadProxy();
	virtual ~IThreadProxy();
	//创建一个虚方法创建线程使用
	virtual void CreateSafeThread() = 0;

	//创建挂起的接口虚方法
	virtual void SuspendThread() = 0;
	//创建唤醒的接口虚方法
	virtual void WakeupThread() = 0;
	//公开代理
	FORCEINLINE FSimpleDelegate& GetThreadDelegate() { return ThreadDelegate;  }
	FORCEINLINE FThreadLambda& GetThreadLambda() { return ThreadLambda; }
	FORCEINLINE FThreadHandle GetThreadHandle() { return SimpleThreadHandle; }

protected:
	FSimpleDelegate ThreadDelegate;
	FThreadLambda ThreadLambda;

private:
	//创建一个句柄
	TSharedPtr<FSimpleThreadHandle> SimpleThreadHandle;
};