#pragma once
class Player;
class Enemy;
class BattleSystem
{
public:
	BattleSystem() {};
	~BattleSystem() {};

	void Init();
	void Update();

	void SetPlayer(const std::weak_ptr<Player> a_player);
	
	void SetEnemy(const std::weak_ptr<Enemy>a_enemy);
	

private:
	std::weak_ptr<Player> m_wpPlayer;
	std::weak_ptr<Enemy> m_wpEnemy;

	int m_playerSpe;
	int m_playerATB;

	int m_battleCount;
};