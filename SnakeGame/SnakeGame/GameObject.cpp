#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	this->position = Position();
}

void GameObject::SetPosition(Position position)
{
	this->position = position;
}

Position GameObject::GetPosition()
{
	return this->position;
}

void GameObject::SetNextGameObject(GameObject * gameObject)
{
	this->nextGameObject = gameObject;
}

GameObject GameObject::GetNextGameObject()
{
	return *this->nextGameObject;
}


GameObject::~GameObject()
{
	delete this->nextGameObject;
}
