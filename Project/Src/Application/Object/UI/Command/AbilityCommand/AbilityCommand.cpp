#include "AbilityCommand.h"
#include"../../../Character/Player/Player.h";

void AbilityCommand::Init()
{
	UiBase::Init();
	m_tex.Load("Asset/Textures/UI/Ability1.png");

	m_rectAngle = { 0,0,128,128 };
	m_tMat = Math::Matrix::CreateTranslation(150, -80, 0);
	texHeight = 128;
	texWide = 128;
	m_bShow = true;
}

void AbilityCommand::Release()
{
	m_tex.Release();
}


