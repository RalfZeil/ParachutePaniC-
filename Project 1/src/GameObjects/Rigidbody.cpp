#include "Rigidbody.h"
#include "../GameData.h"

Rigidbody::Rigidbody() 
{
	m_enableGravity = false;
	m_clampToScreen = false;
	m_speed = 0;
	m_acceleration = 0;
	m_force = 0;
	m_friction = 0;
	m_deltaForce = 0;
	m_mass = 0;
}

Rigidbody::Rigidbody(bool enableGravity, bool clampToScreen, float mass) 
	: m_enableGravity(enableGravity), m_clampToScreen(clampToScreen), m_mass(mass)
{
	m_speed = 200;
	m_acceleration = 0;
	m_force = 0;
	m_friction = 0;
	m_deltaForce = 0;
}

void Rigidbody::Update(GameObject* gameObject, float dt)
{
	m_deltaForce = m_force - m_friction;
	m_acceleration += m_deltaForce / m_mass;

	if (m_acceleration > 0)
	{
		m_friction = GRAVITY_CONSTANT * FRICTION_COEFFICIENT;
	};
	if (m_acceleration < 0)
	{
		m_friction = -(GRAVITY_CONSTANT * FRICTION_COEFFICIENT);
	}

	gameObject->ChangePosistion( Vector2(
		gameObject->GetPosistion().x + (m_acceleration) * dt * m_forceDirection.x, 
		gameObject->GetPosistion().y + (m_acceleration) * dt * m_forceDirection.y
	));
}

void Rigidbody::ClampObject(GameObject* gameObject) 
{
	if (gameObject->GetPosistion().x < 0)
	{
		gameObject->ChangePosistion(Vector2(0, gameObject->GetPosistion().y));
		if (m_acceleration < 0) { m_acceleration = 0.f; }
	}

	else if (gameObject->GetPosistion().x > SCREEN_WIDTH)
	{
		gameObject->ChangePosistion(Vector2(SCREEN_WIDTH, gameObject->GetPosistion().y));
		if (m_acceleration > 0) { m_acceleration = 0.f; }
	}
}

void Rigidbody::SetForce(const Vector2& forceVector)
{
	m_force = Vector2::Magnitude(forceVector);
	m_forceDirection = Vector2::Normalize(forceVector);
}

