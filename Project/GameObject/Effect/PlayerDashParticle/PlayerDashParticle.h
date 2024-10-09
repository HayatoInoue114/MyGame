#pragma once
#include "IParticle.h"
#include "ParticleManager.h"

/* PlayerDashParticleクラス */
class PlayerDashParticle : public IParticle {

public: // メンバ関数

	// コンストラクタ、デストラクタ
	PlayerDashParticle() {};
	~PlayerDashParticle() {};

	// 初期化処理、更新処理
	void Initialize() override;
	void Update() override;


	void AddParticle(uint32_t texture, Vector3 pos) override;

private:

};

