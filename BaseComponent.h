#pragma once
class BaseComponent
{
protected:
	bool parented = false;
	void* parent = nullptr;
public:
	virtual ~BaseComponent() {};
	BaseComponent() {};
	virtual void Update(float timeElapsed) {};
	virtual void FixedUpdate() {};
	
	bool SetParent(void *ent) {
		if (!parented) {
			parent = ent;
			parented = true;
			return true;
		}
		return false;
	}
};

