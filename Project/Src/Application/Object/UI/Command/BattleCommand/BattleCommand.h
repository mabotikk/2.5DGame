#pragma once
#include"../../UiBase.h"

class BattleCommand :public UiBase
{
public:
	BattleCommand() {};
	~BattleCommand()	override { Release(); };

	void Init()			override;
	
	
private:
	void Release();
};