#include "Enemy.h"

void Enemy::Init()
{
	m_poly.SetMaterial("Asset/Textures/Enemy/enemy2.png");
	m_pos = { -1,0,0 };
	m_poly.SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	m_objType = enemy;
	m_poly.SetSplit(3,1);
	m_poly.SetUVRect(0);
	m_poly.SetScale(0.5);

	Hp = 500;
	Atk = 50;
	Def = 50;
	Spe = 100;
}

void Enemy::Update()
{
	m_sMat = Math::Matrix::CreateScale(2, 1, 1);
	m_tMat = Math::Matrix::CreateTranslation(m_pos);
	m_mWorld = m_sMat*m_tMat;
}
