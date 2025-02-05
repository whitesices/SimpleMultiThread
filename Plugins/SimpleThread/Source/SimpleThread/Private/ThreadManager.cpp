#include "ThreadManager.h"

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
