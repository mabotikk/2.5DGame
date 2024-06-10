#include "Meteor.h"

void Meteor::Init()
{
	UiBase::Init();
	m_tex.Load("Asset/Textures/UI/Action/meteo.png");

	m_rectAngle = { 0,0,256,128 };
	m_tMat = Math::Matrix::CreateTranslation(0, 200, 0);
	texHeight = 128;
	texWide = 256;
	m_bShow = true;
	m_displayTime = 0;
}

void Meteor::Update()
{
	m_displayTime++;
	if (m_displayTime > 50)
	{
		CloseUi();
	}
}

void Meteor::Release()
{
	m_tex.Release();
}
