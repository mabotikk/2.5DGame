#pragma once
#include"../../UiBase.h"

class ATBPlayer :public UiBase
{
public:
	ATBPlayer() {};
	~ATBPlayer()	override { Release(); }

	void Init()			override;

private:
	void Release();
};