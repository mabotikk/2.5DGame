#pragma once
class GameScene;
//
//struct parameter
//{
//	int Hp;		//HP
//	int Atk;	//攻撃力
//	int Def;	//防御
//	int Spe;	//素早さ
//};

class BaseChara :public KdGameObject
{
public:
	BaseChara() {};
	~BaseChara()	override {};

	void Init()		override;
	void DrawLit()	override;
	void Update()	override;
	void GenerateDepthMapFromLight() override;
	void SetOwner(GameScene* a_owner) { m_owner = a_owner; }
	int GetHp() { return Hp; }
	int GetAtk() { return Atk; }
	int GetDef() { return Def; }
	int GetSpe() { return Spe; }

private:
	void Release();

protected:
	GameScene* m_owner = nullptr;
	
	KdSquarePolygon	m_poly;
	Math::Matrix	m_sMat;
	Math::Matrix	m_rMat;
	Math::Matrix	m_tMat;
	Math::Vector3	m_pos;
	
	int Hp;		//HP
	int Atk;	//攻撃力
	int Def;	//防御
	int Spe;	//素早さ

	//parameter m_parameter;
};