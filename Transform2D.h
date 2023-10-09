#pragma once
#include "BaseComponent.h"
#include "Vector2D.h"
class Transform2D : public BaseComponent
{
	Vector2D position;
	float rotation;
	Vector2D scale;
public:
	~Transform2D() {
		position.x = 0.0f;
		position.y = 0.0f;
		rotation = 0.0f;
		scale.x = 1;
		scale.y = 1;
	}
	void Update() {

	}
	//Setters
	void SetPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}
	void SetPosition(Vector2D pos) {
		position.x = pos.x;
		position.y = pos.y;
	}
	void SetRotation(float rot) {
		rotation = rot;
	}
	void SetScale(float x, float y) {
		scale.x = x;
		scale.y = y;
	}

	//Getters
	Vector2D* GetPosition() {
		return new Vector2D(position);
	}
	float GetRotation() {
		return rotation;
	}
	Vector2D* GetScale() {
		return new Vector2D(scale);
	}
};

