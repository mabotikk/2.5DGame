#include "BattleCommand.h"


void BattleCommand::Init()
{
	UiBase::Init();
	m_tex.Load("Asset/Textures/UI/Window6.png");

	m_rectAngle = { 0,0,128,128 };
	m_tMat = Math::Matrix::CreateTranslation(130, -100, 0);
	texHeight = 128;
	texWide = 128;
	m_bShow = true;
}

void BattleCommand::Release()
{
	m_tex.Release();
}


