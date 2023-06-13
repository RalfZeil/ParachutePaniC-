#include "Rigidbody.h"
#include "../GameData.h"
#include "GameObject.h"

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
	m_speed = 40;
	m_acceleration = 0;
	m_force = 0;
	m_friction = 0;
	m_deltaForce = 0;
}

void Rigidbody::Update(GameObject* gameObject, float dt)
{
	//change friction so it applies fricion on the correct side
	if (m_acceleration > 0)
	{
		m_friction = GRAVITY_CONSTANT * FRICTION_COEFFICIENT;
	};
	if (m_acceleration < 0)
	{
		m_friction = -(GRAVITY_CONSTANT * FRICTION_COEFFICIENT);
	}

	//calculate acceleration
	m_deltaForce = m_force - m_friction;
	m_acceleration += m_deltaForce / m_mass;

	gameObject->ChangePosistion(rmath::Vector2(
		gameObject->GetPosistion().x + (m_acceleration) * dt * m_forceDirection.x,
		gameObject->GetPosistion().y + (m_acceleration) * dt * m_forceDirection.y
	));

	if (m_clampToScreen) { ClampObject(gameObject); }

	//reset force at the end
	m_force = 0;
}

void Rigidbody::ClampObject(GameObject* gameObject) 
{
	if (gameObject->GetPosistion().x < 1)
	{
		gameObject->ChangePosistion(rmath::Vector2(0, gameObject->GetPosistion().y));
		if (m_acceleration < 0) { Reset(); }
	}

	else if (gameObject->GetPosistion().x > SCREEN_WIDTH)
	{
		gameObject->ChangePosistion(rmath::Vector2(SCREEN_WIDTH, gameObject->GetPosistion().y));
		if (m_acceleration > 0) { Reset(); }
	}
}

void Rigidbody::SetForce(const rmath::Vector2& forceVector)
{
	//Seperate force and the direction
	m_force = rmath::Vector2::Magnitude(forceVector);
	m_forceDirection = rmath::Vector2::Normalize(forceVector);
}

void Rigidbody::Reset() 
{
	m_speed = 40;
	m_acceleration = 0;
	m_force = 0;
	m_friction = 0;
	m_deltaForce = 0;
}

