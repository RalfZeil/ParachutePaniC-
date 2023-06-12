#pragma once
#include "GameObject.h"

class Rigidbody {

private: 
	bool m_enableGravity;
	bool m_clampToScreen;

	Vector2 m_forceDirection;

	float m_speed;
	float m_acceleration;
	float m_force;
	float m_friction;
	float m_deltaForce;
	float m_mass;

	void ClampObject(GameObject* gameObject);

public:
	Rigidbody();
	Rigidbody(bool enableGravity, bool clampToScreen, float mass);
	void Update(GameObject* gameObject, float dt);
	void SetForce(const Vector2& forceVector);
};