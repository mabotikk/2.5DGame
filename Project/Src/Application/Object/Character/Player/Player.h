#pragma once
#include"../BaseChara.h"

class BattleCommand;
class AbilityCommand;
class BattleCursor;
class AbilityCursor;
enum
{
	PlayerAttack,
	PlayerAbility,
	PlayerItem,
	PlayerEscape,
};

class Player :public BaseChara,  public std::enable_shared_from_this<Player>
{
	
public:
	Player() {};
	~Player()		override { Release(); };
	
	std::shared_ptr<Player>playerThis() { return shared_from_this(); }

	void Init()		override;
	void Update()	override;
	
	void Action(int a_action);
	void Ability(int a_Ability);
	void PreAttack();
private:
	void Release();
	std::weak_ptr<BattleCommand>	m_wpBattleCommand;
	std::weak_ptr<BattleCursor>		m_wpBattleCursor;
	std::weak_ptr<AbilityCommand>	m_wpAbilityCommand;
	std::weak_ptr<AbilityCursor>	m_wpAbilityCursor;
	float	m_animeFrame	=0;
	bool	m_bAnime		=0;
	bool	m_keyFlgK		=0;
	
};