#pragma once
#include "BaseComponent.h"
#include "BaseEntity.h"
#include "Vector2D.h"
#include "Transform2D.h"
class PhyicsComponent : public BaseComponent
{
	Vector2D gravity;
	Vector2D velocity;
public:
	~PhyicsComponent() {
		gravity = Vector2D(0, -9.8f);
	}
	PhyicsComponent() {
		gravity = Vector2D(0, -9.8f);
	}
	void FixedUpdate() {
		Transform2D *t = ((BaseEntity*)parent)->GetComponent<Transform2D>();
		if (t != nullptr) {
			velocity += gravity * (1.0f / 30);
			Vector2D *lastPos = t->GetPosition();
			*lastPos += velocity * (1.0f / 30);
			t->SetPosition(*lastPos);
		}
	};
	Vector2D GetVelocity() {
		return Vector2D(velocity);
	}
};

