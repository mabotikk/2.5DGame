#include "Player.h"
#include"../../UI/Command/BattleCommand/BattleCommand.h"
#include"../../UI/Cursor/BattleCursor/BattleCursor.h"
#include"../../UI/Command/AbilityCommand/AbilityCommand.h"
#include"../../UI/Cursor/AbilityCursor/AbilityCursor.h"
#include"../../../Scene/GameScene/GameScene.h"
#include"../../UI/Execution/Attack/Attack.h"
#include"../../UI/Execution/Meteor/Meteor.h"

void Player::Init()
{
	BaseChara::Init();
	m_poly.SetMaterial("Asset/Textures/Player/san.png");
	m_pos = { 1,0,0 };
	m_poly.SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	m_objType = player;
	m_poly.SetScale(0.3);
	m_poly.SetSplit(9, 6);
	
	m_animeFrame = 0;
	m_bAnime = 0;
	m_keyFlgK = 0;

	m_parameter.Hp = 500;
	m_parameter.Atk = 50;
	m_parameter.Def = 50;
	m_parameter.Spe = 50;
}

void Player::Update()
{
	//待機アニメーション
	
	if (!m_bAnime)
	{
		m_animeFrame += 0.03;
		if (m_animeFrame > 2)
		{
			m_animeFrame = 0;
		}
	}
	
	m_poly.SetUVRect((int)m_animeFrame);

	//攻撃モーション
	
	if (GetAsyncKeyState('K') & 0x8000)
	{

		if (!m_keyFlgK)
		{
			PreAttack();
			m_keyFlgK = true;
		}
	}
	else
	{
			m_keyFlgK = false;
	}
	
	m_tMat = Math::Matrix::CreateTranslation(m_pos);
	m_mWorld = m_tMat;
}

void Player::Action(int a_action)
{
	if (m_wpBattleCommand.expired() == true)return;
	if (m_wpBattleCursor.expired() == true)return;
	//バトルコマンド消すローカル
	const std::shared_ptr<BattleCommand> spBattleCommand = m_wpBattleCommand.lock();
	const std::shared_ptr<BattleCursor> spBattleCursor = m_wpBattleCursor.lock();
	
	std::shared_ptr<AbilityCommand>abilityCommand;
	std::shared_ptr<AbilityCursor>abilityCursor;

	//action結果
	std::shared_ptr<Attack>attack;

	switch (a_action)
	{
	case PlayerAttack:
		m_pos.x = 1;
		m_bAnime = false;
		//バトルコマンド,カーソル消す
		spBattleCommand->CloseUi();
		spBattleCursor->CloseUi();

		//たたかう文字出す
		attack = std::make_shared<Attack>();
		attack->Init();
		m_owner->AddObject(attack);
		break;
	case PlayerAbility:

		//アビリティコマンドを出す
		
		abilityCommand = std::make_shared<AbilityCommand>();
		abilityCommand->Init();
		m_owner->AddObject(abilityCommand);
		m_wpAbilityCommand = abilityCommand;

		//カーソル(アビリティ用)
		
		abilityCursor = std::make_shared<AbilityCursor>();
		abilityCursor->Init();
		m_owner->AddObject(abilityCursor);
		abilityCursor->SetPlayer(playerThis());
		m_wpAbilityCursor = abilityCursor;
		
		spBattleCursor->CloseUi();
		break;
	case PlayerItem:
		m_pos.x = 1;
		m_bAnime = false;
		spBattleCommand->CloseUi();
		spBattleCursor->CloseUi();
		
		break;
	case PlayerEscape:
		m_pos.x = 1;
		m_bAnime = false;
		spBattleCommand->CloseUi();
		spBattleCursor->CloseUi();
		break;
	}
}

void Player::Ability(int a_Ability)
{
	//バトルコマンド消すローカル
	if (m_wpBattleCommand.expired() == true)return;
	if (m_wpAbilityCommand.expired() == true)return;
	if (m_wpAbilityCursor.expired() == true)return;
	
	const std::shared_ptr<BattleCommand> spBattleCommand = m_wpBattleCommand.lock();
	//Abilityコマンド
	const std::shared_ptr<AbilityCommand> spAbilityCommand = m_wpAbilityCommand.lock();
	const std::shared_ptr<AbilityCursor> spAbilityCursor = m_wpAbilityCursor.lock();
	
	//action結果
	std::shared_ptr<Meteor>meteor;

	switch (a_Ability)
	{
	case 0:
		m_pos.x = 1;
		m_bAnime = false;
		//たたかう文字出す
		meteor = std::make_shared<Meteor>();
		meteor->Init();
		m_owner->AddObject(meteor);
		break;
	case 1:
		m_pos.x = 1;
		m_bAnime = false;
		
		break;
	case 2:
		m_pos.x = 1;
		m_bAnime = false;
		
		break;
	}
	spBattleCommand->CloseUi();
	spAbilityCommand->CloseUi();
	spAbilityCursor->CloseUi();
}

void Player::PreAttack()
{
	if (!m_bAnime)
	{
		m_pos.x = 0;
		m_animeFrame = 22;
		m_bAnime = true;

		//ここでコマンドを表示
		std::shared_ptr<BattleCommand>battleCommand;
		battleCommand = std::make_shared<BattleCommand>();
		battleCommand->Init();
		m_owner->AddObject(battleCommand);
		m_wpBattleCommand = battleCommand;

		//カーソル(バトル用)
		std::shared_ptr<BattleCursor>battleCursor;
		battleCursor = std::make_shared<BattleCursor>();
		battleCursor->Init();
		battleCursor->SetPlayer(playerThis());
		m_owner->AddObject(battleCursor);
		m_wpBattleCursor = battleCursor;

	}
	else
	{
		m_pos.x = 1;
		m_bAnime = false;
	}
}

void Player::Release()
{
	
}



