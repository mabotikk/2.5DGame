#include "ATBPlayer.h"

void ATBPlayer::Init()
{
	UiBase::Init();
	m_tex.Load("Asset/Textures/UI/waku.png");

	m_rectAngle = { 0,0,75,10 };
	m_tMat = Math::Matrix::CreateTranslation(550, 140, 0);
	m_sMat = Math::Matrix::CreateScale(2);
	texHeight = 10;
	texWide = 80;
	m_bShow = true;
}

void ATBPlayer::Release()
{
	m_tex.Release();
}
