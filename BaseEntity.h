#pragma once
#include <vector>
#include "BaseComponent.h"
#include <typeinfo>
class BaseEntity
{
private:
	std::vector<BaseComponent*> components;
public:
	~BaseEntity() {};
	virtual void Update(float timeElapsed) {
		for (int i = 0; i < components.size(); i++) {
			components[i]->Update(timeElapsed);
		}
	};
	virtual void FixedUpdate() {
		for (int i = 0; i < components.size(); i++) {
			components[i]->FixedUpdate();
		}
	};
	void virtual AddComponent(BaseComponent &component) {
		component.SetParent((void*)this);
		components.push_back(&component);
	}
	/*
	template <typename T>
	T* GetComponent() {
		for (int i = 0; i < components.size(); i++) {
			if (typeid(components[i]).name() == typeid(T).name()) {
				return &components[i];
			}
		}
	}
	*/
	template <typename T>
	T* GetComponent() {
		for (int i = 0; i < components.size(); i++) {
			if (typeid(*components[i]) == typeid(T)) {
				return dynamic_cast<T*>(components[i]);
			}
		}
		return nullptr; // Return nullptr if the component is not found
	}
};

