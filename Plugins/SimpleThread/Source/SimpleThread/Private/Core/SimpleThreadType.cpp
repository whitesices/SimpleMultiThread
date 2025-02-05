#pragma once

#include "Core/SimpleThreadType.h"
#include "Interface/ProxyInterface.h"

//定义一个随机函数
uint64 SpawnUniqueID()
{
	return FMath::Abs( FMath::RandRange(100,1256343) + FDateTime::Now().GetTicks() );
}

FSimpleThreadHandle::FSimpleThreadHandle():GUIDTypeA(SpawnUniqueID()),GUIDTypeB(SpawnUniqueID()),GUIDTypeC(SpawnUniqueID()),GUIDTypeD(SpawnUniqueID())
{

}

IThreadProxy::IThreadProxy():SimpleThreadHandle( MakeShareable( new FSimpleThreadHandle ) )
{

}

IThreadProxy::~IThreadProxy()
{

}