#pragma once

class Back :public KdGameObject
{
public:
	Back() {};
	~Back()override {};

	void Init()override;
	void DrawUnLit()override;
private:
	KdSquarePolygon m_poly;

	Math::Matrix scaleMat;
	Math::Matrix transMat;
	Math::Matrix rotateMat;
};