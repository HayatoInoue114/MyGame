#include "PlayerDashParticle.h"

void PlayerDashParticle::Initialize()
{
	name_ = "PlayerDashParticle";

	wt_.Initialize();
	uv_.Initialize();

	wt_.scale = { 1.5f, 1.5f, 1.5f };
	wt_.translate = Vector3::zero;

	perSecond_ = 1;

	direction_ = Vector3::zero;

	Scope scope = { -0.03f, 0.03f };
	velocity_ = {
		0.0f,
		RandomGenerator::getRandom(scope),
		0.0f,
	};

	acceleration_ = { 0.0f, 0.0f, 0.0f };

	minLifetime_ = 1.0f;
	maxLifetime_ = 20.0f;
	lifeTime_ = 0;

	color_ = { 1.0f, 1.0f, 1.0f, 1.0f };

	isActive_ = true;
}

void PlayerDashParticle::Update()
{
	wt_.UpdateMatrix();
	uv_.UpdateMatrix();

	lifeTime_++;

	if (lifeTime_ >= maxLifetime_) {
		isActive_ = false;
	}

	wt_.translate += velocity_;
	velocity_ -= acceleration_;

	color_.w =
		1.0f + (0.0f - 1.0f) * Ease::InCirc(lifeTime_ / maxLifetime_);

	if (color_.w <= 0.0f) {
		isActive_ = false;
	}
}

void PlayerDashParticle::AddParticle(uint32_t texture, Vector3 pos)
{
	std::unique_ptr<PlayerDashParticle> newParticle = IParticle::Create<PlayerDashParticle>();
	newParticle->SetTranslate(pos);
	ParticleManager::GetInstance()->AddParticle(name_, std::move(newParticle));
	ParticleManager::GetInstance()->SetTexture(name_, texture);
}
