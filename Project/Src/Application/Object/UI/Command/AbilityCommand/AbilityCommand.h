#pragma once
#include"../../UiBase.h"

class AbilityCommand :public UiBase
{
public:
	AbilityCommand() {};
	~AbilityCommand()	override { Release(); }

	void Init()			override;

private:
	void Release();
};