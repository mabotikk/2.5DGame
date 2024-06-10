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

	void SetPlayer(const std::weak_ptr<Player>player);
	
	void SetEnemy(const std::weak_ptr<Enemy>enemy);
	

private:
	std::weak_ptr<Player> m_wpPlayer;
	std::weak_ptr<Enemy> m_wpEnemy;

	int m_battleCount;
};