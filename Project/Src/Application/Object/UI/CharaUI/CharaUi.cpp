#include "CharaUi.h"

void CharaUi::Init()
{
	UiBase::Init();
	m_tex.Load("Asset/Textures/UI/name.png");

	m_rectAngle = { 0,0,487,54 };
	m_tMat = Math::Matrix::CreateTranslation(350, 160, 0);
	texHeight = 54;
	texWide = 487;
	m_bShow = true;
}

void CharaUi::Release()
{
	m_tex.Release();
}
