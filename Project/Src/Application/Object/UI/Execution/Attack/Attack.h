#pragma once
#include"../../UiBase.h"

class Attack :public UiBase
{
public:
	Attack() {};
	~Attack()override { Release(); };

	void Init()			override;
	void Update()		override;
private:
	void Release();

	float m_displayTime;
};