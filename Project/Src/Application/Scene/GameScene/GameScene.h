#pragma once

#include"../BaseScene/BaseScene.h"

class GameScene : public BaseScene
{
public :

	GameScene() { Init(); }
	~GameScene() {}

private:

	void Event() override;
	void Init() override;

	float	cameraMoveY;
	bool	cameraYF;


	Math::Matrix m_space;
	Math::Matrix m_cameraMat;
	Math::Matrix m_cameraRXMat;
	Math::Matrix m_cameraRYMat;
	Math::Matrix m_cameraTMat;
};
