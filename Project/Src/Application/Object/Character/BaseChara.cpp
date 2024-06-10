#include "BaseChara.h"

void BaseChara::Init()
{
	m_pos = { 0,0,0 };

	
}

void BaseChara::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(m_poly, m_mWorld);
}

void BaseChara::Update()
{
}

void BaseChara::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(m_poly, m_mWorld);
}

void BaseChara::Release()
{
}
