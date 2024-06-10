#pragma once
#include"../../UiBase.h"
class Player;
class BattleCursor :public UiBase
{
public:

	
	

	enum
	{
		Attack,
		Ability = 23,
		Item = 46,
		Escape = 69,
	};

	BattleCursor() {};
	~BattleCursor()		override { Release(); };

	void Init()			override;
	void Update()		override;
	
	bool GetActionFlg(){return m_actionFlg;}

	bool GetAction() { return m_choiceAction; }
private:
	void Release();

	float					m_anime	= 0;
	int						m_choice= 0;

	static const int		keyFlgMax = 10;
	bool					keyFlg[keyFlgMax];
	
	static const int		ActionDiff = 23;
	int m_choiceAction = 0;

	bool m_actionFlg = 0;
};