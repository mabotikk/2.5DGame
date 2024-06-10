#pragma once
class Player;
class GameScene;

class UiBase :public KdGameObject
{
public:
	UiBase(){};
	~UiBase()		override {};

	void Init()			override;
	void DrawSprite()	override;
	void Update()		override;
	void SetPlayer(const std::shared_ptr<Player>player )
	{
		m_wpPlayer = player;
	}
	void SetOwner(GameScene* a_owner) { m_owner = a_owner; }
	void CloseUi() { m_isExpired = true; }
private:
	void Release();

protected:
	GameScene* m_owner = nullptr;
	std::weak_ptr<Player>	m_wpPlayer;
	Math::Rectangle			m_rectAngle;	//矩形
	KdTexture				m_tex;
	Math::Vector3			m_pos;


	Math::Matrix			m_sMat	= Math::Matrix::Identity;
	Math::Matrix			m_rMat	= Math::Matrix::Identity;
	Math::Matrix			m_tMat	= Math::Matrix::Identity;

	bool					m_bShow	= 0;

	int texHeight=0;
	int texWide=0;
};