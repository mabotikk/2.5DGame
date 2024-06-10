#include "BattleCursor.h"
#include"../../../Character/Player/Player.h";

void BattleCursor::Init()
{
	UiBase::Init();
	m_tex.Load("Asset/Textures/UI/corsur.png");

	m_rectAngle = { 0,0,16,16};
	for (int i = 0; keyFlgMax > i; i++)
	{
		keyFlg[i] = 0;
	}
	texHeight = 16;
	texWide	=	16;
	m_bShow=true;
}



void BattleCursor::Update()
{
	if (m_wpPlayer.expired() == true)return;
	const std::shared_ptr<Player> spPlayer = m_wpPlayer.lock();
	
	if (m_bShow)
	{
		//カーソルの左右移動
		m_anime += 0.3;
		if (m_anime > 10)m_anime = 0;

		if (GetAsyncKeyState('W') & 0x8000)
		{
			if (!keyFlg[0])
			{
				if (m_choice > 0)
				{
					m_choice -= ActionDiff;
				}
				keyFlg[0] = true;
			}
		}
		else
		{
			keyFlg[0] = false;
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			if (!keyFlg[1])
			{
				if (m_choice < ActionDiff*3)
				{
					m_choice += ActionDiff;
				}
				keyFlg[1] = true;
			}
		}
		else
		{
			keyFlg[1] = false;
		}

		//Fで決定プレイヤーに選択されたコマンドを返す
		if (GetAsyncKeyState('F') & 0x8000)
		{
			if (!keyFlg[2])
			{
				switch (m_choice)
				{
				case Attack:
					spPlayer->Action(Attack / ActionDiff);
					break;
				case Ability:
					spPlayer->Action(Ability / ActionDiff);
					break;
				case Item:
					spPlayer->Action(Item / ActionDiff);
					break;
				case Escape:
					spPlayer->Action(Escape / ActionDiff);
					break;
				}
				keyFlg[2] = true;
			}
		}
		else
		{
			keyFlg[2] = false;
		}
		


		m_tMat = Math::Matrix::CreateTranslation(70 - m_anime, -60 - m_choice, 0);
		m_rMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(90));
		m_sMat = Math::Matrix::CreateScale(2);
	}
	else
	{
		m_choice = 0;
	}
}

void BattleCursor::Release()
{
	m_tex.Release();
}
