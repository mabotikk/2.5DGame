#include "Back.h"

void Back::Init()
{
	m_poly.SetMaterial("Asset/Textures/");
	scaleMat = Math::Matrix::CreateScale(300, 300, 1);
	transMat = Math::Matrix::CreateTranslation(0, 0, 50);
	m_mWorld = scaleMat * transMat;
}

void Back::DrawUnLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(m_poly, m_mWorld);
}
