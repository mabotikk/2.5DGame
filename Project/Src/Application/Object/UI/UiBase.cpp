#include "UiBase.h"

void UiBase::Init()
{
	m_pos = {};
	m_sMat = Math::Matrix::Identity;
	m_rMat = Math::Matrix::Identity;
	m_tMat = Math::Matrix::Identity;
	m_bShow = false;
	m_isExpired = false;
}

void UiBase::DrawSprite()
{
	if (m_bShow)
	{
		m_mWorld = m_sMat * m_rMat * m_tMat;
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, texWide, texHeight, &m_rectAngle);
		m_mWorld = Math::Matrix::Identity;
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
	}
}

void UiBase::Update()
{
	
}

void UiBase::Release()
{
}
