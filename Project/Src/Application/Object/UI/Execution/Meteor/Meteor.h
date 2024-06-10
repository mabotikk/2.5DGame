#pragma once
#include"../../UiBase.h"

class Meteor :public UiBase
{
public:
	Meteor() {};
	~Meteor()override { Release(); };

	void Init()			override;
	void Update()		override;
private:
	void Release();

	float m_displayTime;
};