#pragma once
#include"../BaseChara.h"
class Enemy :public BaseChara
{
public:
	Enemy() {};
	~Enemy() override {};

	void Init()override;
	void Update()override;

	
private:
	

	int m_anime;
	float m_animeInterval;
	bool m_animeFlg;

};