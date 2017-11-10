#pragma once

#include "Position.h"

class GameObject : public Position
{
	Position position;
	GameObject *nextGameObject;
public:
	GameObject();
	void SetPosition(Position position);
	Position GetPosition();
	void SetNextGameObject(GameObject *gameObject);
	GameObject GetNextGameObject();
	~GameObject();
};