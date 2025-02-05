#pragma once

#include "CoreMinimal.h"

struct SIMPLETHREAD_API FSimpleThreadHandle : public TSharedFromThis<FSimpleThreadHandle>
{
	//声明一个构造函数
	FSimpleThreadHandle();

	//重载一个操作符
	bool operator==(const FSimpleThreadHandle& SimpleThreadHandle)
	{
		return  (this->GUIDTypeA == SimpleThreadHandle.GUIDTypeA) &&
			(this->GUIDTypeB == SimpleThreadHandle.GUIDTypeB) &&
			(this->GUIDTypeC == SimpleThreadHandle.GUIDTypeC) &&
			(this->GUIDTypeD == SimpleThreadHandle.GUIDTypeD);
	}
protected:
	uint64  GUIDTypeA;
	uint64  GUIDTypeB;
	uint64  GUIDTypeC;
	uint64  GUIDTypeD;

};

//定义一个弱指针
typedef TWeakPtr<FSimpleThreadHandle> FThreadHandle;
typedef TFunction<void()> FThreadLambda;