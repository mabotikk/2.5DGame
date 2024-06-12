#include "GameScene.h"
#include"../SceneManager.h"
#include"../../Object/Terrain/Terrain.h"
#include"../../Object/Character/Player/Player.h"
#include"../../Object/Character/Enemy/Enemy.h"
#include"../../Object/UI/Command/abilityCommand/abilityCommand.h"
#include"../../Object/UI/Cursor/BattleCursor/BattleCursor.h"
#include"../../Object/UI/Cursor/AbilityCursor/AbilityCursor.h"
#include"../../Object/UI/CharaUI/CharaUi.h"
#include"../../Object/UI/ATBGauge/ATBPlayer/ATBPlayer.h"

void GameScene::Event()
{
	
	if (!cameraYF)
	{
		if (cameraMoveY > 10)
		{
			cameraYF = true;
		}
		else
		{
			cameraMoveY+=0.05;
		}	
	}
	if (cameraYF)
	{
		if (cameraMoveY < -10)
		{
			cameraYF = false;
		}
		else
		{
			cameraMoveY-=0.05;
		}
	}
	
	
	m_space = Math::Matrix::CreateTranslation(0, 0, 0);
	m_cameraRXMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(10));
	m_cameraRYMat = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(cameraMoveY));
	m_cameraTMat = Math::Matrix::CreateTranslation(0, 1, -2);
	m_cameraMat = m_cameraRXMat * m_cameraTMat* m_cameraRYMat;
	//m_cameraMat *= m_space;
	m_camera->SetCameraMatrix(m_cameraMat);
}

void GameScene::Init()
{
	KdShaderManager::Instance().WorkAmbientController().SetDirLightShadowArea({ 25.0f, 25.0f }, 30.0f);
	
	//カメラ
	m_camera = std::make_unique<KdCamera>();
	cameraYF = false;

	//平行光(方向、色)
	//KdShaderManager::Instance().WorkAmbientController().SetDirLight({ 5,-5,5 }, { 2,2,2 });


	cameraMoveY = 0;
	//地形
	std::shared_ptr<Terrain>terrain;
	terrain = std::make_shared<Terrain>();
	terrain->Init();
	m_objList.push_back(terrain);

	//プレイヤー
	std::shared_ptr<Player>player;
	player = std::make_shared<Player>();
	player->Init();
	player->SetOwner(this);
	m_objList.push_back(player);

	//エネミー
	std::shared_ptr<Enemy>enemy;
	enemy = std::make_shared<Enemy>();
	enemy->Init();
	m_objList.push_back(enemy);

	//Name
	std::shared_ptr<CharaUi>charaui;
	charaui = std::make_shared<CharaUi>();
	charaui->Init();
	m_objList.push_back(charaui);
	//playerATB
	std::shared_ptr<ATBPlayer>atbPlayer;
	atbPlayer = std::make_shared<ATBPlayer>();
	atbPlayer->Init();
	m_objList.push_back(atbPlayer);
}
