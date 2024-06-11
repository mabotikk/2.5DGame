#include "BattleSystem.h"
#include "../Object/Character/Player/Player.h"
#include "../Object/Character/Enemy/Enemy.h"

void BattleSystem::Init()
{
	m_battleCount = 0;
	m_playerATB = 100;
}

void BattleSystem::Update()
{
	if (m_wpPlayer.expired() == true)return;
	if (m_wpEnemy.expired() == true)return;

	m_battleCount++;
	const std::shared_ptr<Player>player = m_wpPlayer.lock();
	const std::shared_ptr<Enemy>enemy = m_wpEnemy.lock();
	
	m_battleCount += m_playerSpe;
	if (m_playerATB < m_battleCount)
	{
		m_battleCount = 0;
		//攻撃可能
	}

}

void BattleSystem::SetPlayer(const std::weak_ptr<Player> a_player)
{
	if (m_wpPlayer.expired() == true)return;

	m_wpPlayer = a_player;
	const std::shared_ptr<Player>player = m_wpPlayer.lock();

	m_playerSpe = player->GetSpe();

}

void BattleSystem::SetEnemy(const std::weak_ptr<Enemy> a_enemy)
{
	if (m_wpEnemy.expired() == true)return;

	m_wpEnemy = a_enemy; 
	//const std::shared_ptr<Enemy>enemy = m_wpEnemy.lock();


}
