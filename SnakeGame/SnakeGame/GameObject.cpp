#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	Position::SetPosition(ZERO, ZERO);
	this->nextGameObject = nullptr;
}

void GameObject::SetNextGameObject(GameObject * gameObject)
{
	this->nextGameObject = gameObject;
}

GameObject * GameObject::GetNextGameObject()
{
	return this->nextGameObject;
}

void GameObject::DeleteNextGameObject()
{
	delete this->nextGameObject;
	this->nextGameObject = nullptr;
}

void GameObject::SetDirection(int direction)
{
	this->direction = direction;
}

int GameObject::GetDirection()
{
	return this->direction;
}

void GameObject::SetAnimeFrame(int animeFrame)
{
	this->animeFrame = animeFrame;
}

int GameObject::GetAnimeFrame()
{
	return animeFrame;
}

void GameObject::SetImage(CImage objectImage)
{
	this->objectImage = objectImage;
}

CImage GameObject::GetImage()
{
	return objectImage;
}

void GameObject::Draw()
{
}


GameObject::~GameObject()
{
	delete this->nextGameObject;
	objectImage.Destroy();
}
