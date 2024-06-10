#include "Terrain.h"

Terrain::Terrain()
{
}

Terrain::~Terrain()
{
}

void Terrain::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Terrain/Terrain.gltf");
	m_objType = terrain;
}

void Terrain::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model,m_mWorld);
}
