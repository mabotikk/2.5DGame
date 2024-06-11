#pragma once
#include"../UiBase.h"

class CharaUi:public UiBase
{
public:
	CharaUi() {};
	~CharaUi()	override { Release(); };

	void Init()			override;


private:
	void Release();
};