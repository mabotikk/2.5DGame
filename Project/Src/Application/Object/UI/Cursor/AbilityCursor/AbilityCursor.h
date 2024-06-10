#pragma once
#include"../../UiBase.h"
class Player;
class AbilityCursor :public UiBase
{
public:

	enum
	{
		Meteo=0,
		Ryubi=26,
		ohka=52,
	};

	AbilityCursor() {};
	~AbilityCursor()	override { Release(); };

	void Init()			override;
	void Update()		override;

private:
	void Release();
	

	float					m_anime = 0;
	int						m_choice = 0;

	static const int		keyFlgMax = 10;
	bool					keyFlg[keyFlgMax];

	static const int		ActionDiff = 26;
};