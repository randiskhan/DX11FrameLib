// TestEntity.cpp
// Impementation file for TestEntity.

#include "TestEntity.h"

TestEntity::TestEntity(CAppBase* pCAppBase) : IEntity(pCAppBase)
{
	Init();
}

TestEntity::~TestEntity(void)
{
	Cleanup();
}

bool		TestEntity::Init(void)
{
	static bool good; good = true;

	_msg = L"";

	return _IsInit = good;
}

bool		TestEntity::Update(void)
{
	static bool good; good = true;
	static int count = 0; ++count;
	static float last = 0;
	static float fps = 0;
	static float interval = 0.5f;

	if (GetFrame()->GetCTimer()->GetTotalElapsed() > last + interval)
	{
		fps = count / interval;
		count = 0;
		last += interval;
	}
	
	if(DoUpdate())
	{
		_msg = 
			ToString(GetFrame()->GetCInput()->GetMouseScreenPos()->x) + 
			L"," + 
			ToString(GetFrame()->GetCInput()->GetMouseScreenPos()->y) +
			L" - FPS: " +
			ToString(fps);
	}

	return good;
}

bool		TestEntity::Render(void)
{
	static bool good; good = true;

	if(DoRender())
	{
		GetFrame()->DrawDebugString(
			_msg, 
			XMFLOAT2(20,20), 
			Colors::Yellow);
	}
	
	return good;
}

void		TestEntity::Cleanup(void)
{
}
