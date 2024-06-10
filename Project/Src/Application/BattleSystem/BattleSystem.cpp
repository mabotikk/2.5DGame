#include "BattleSystem.h"
#include "../Object/Character/Player/Player.h"
#include "../Object/Character/Enemy/Enemy.h"

void BattleSystem::Init()
{
	m_battleCount = 0;
}

void BattleSystem::Update()
{
	if (m_wpPlayer.expired() == true)return;
	if (m_wpEnemy.expired() == true)return;

	m_battleCount++;
	const std::shared_ptr<Player>player = m_wpPlayer.lock();
	const std::shared_ptr<Enemy>enemy = m_wpEnemy.lock();
	
}

void BattleSystem::SetPlayer(const std::weak_ptr<Player> player)
{
	if (m_wpPlayer.expired() == true)return;
	m_wpPlayer = player;
	const std::shared_ptr<Player>player = m_wpPlayer.lock();


}

void BattleSystem::SetEnemy(const std::weak_ptr<Enemy> enemy)
{
	if (m_wpEnemy.expired() == true)return;
	m_wpEnemy = enemy; 
	const std::shared_ptr<Enemy>enemy = m_wpEnemy.lock();


}
