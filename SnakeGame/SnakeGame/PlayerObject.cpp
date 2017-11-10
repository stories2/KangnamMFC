#include "stdafx.h"
#include "PlayerObject.h"


PlayerObject::PlayerObject(Position playerPosition, CString resourcePath, int direction)
{
	Position::SetPosition(playerPosition);
	CImage playerImage;
	playerImage.Load(resourcePath);
	GameObject::SetImage(playerImage);
	GameObject::SetDirection(direction);
	GameObject::SetAnimeFrame(ZERO);
}

void PlayerObject::SetPosition(Position position)
{
	Position::SetPosition(position);
}

Position PlayerObject::GetPosition()
{
	return Position::GetPosition();
}

void PlayerObject::SetPlayerImage(CImage playerImage)
{
	GameObject::SetImage(playerImage);
}

CImage PlayerObject::GetPlayerImage()
{
	return GameObject::GetImage();
}

void PlayerObject::SetDirection(int direction)
{
	GameObject::SetDirection(direction);
}

int PlayerObject::GetDirection()
{
	return GameObject::GetDirection();
}

void PlayerObject::SetNextGameObject(GameObject * nextGameObject)
{
	GameObject::SetNextGameObject(nextGameObject);
}

GameObject * PlayerObject::GetNextGameObject()
{
	return GameObject::GetNextGameObject();
}

GameObject * PlayerObject::GetLastGameObject()
{
	GameObject *indexOfGameObject = GameObject::GetNextGameObject();
	while (indexOfGameObject != nullptr) {
		if (indexOfGameObject->GetNextGameObject() == nullptr) {
			break;
		}
		indexOfGameObject = indexOfGameObject->GetNextGameObject();
	}
	return indexOfGameObject;
}

void PlayerObject::SetAnimeFrame(int animeFrame)
{
	GameObject::SetAnimeFrame(animeFrame);
}

int PlayerObject::GetAnimeFrame()
{
	return GameObject::GetAnimeFrame();
}

void PlayerObject::Draw()
{
	GameObject::Draw();
}

PlayerObject::~PlayerObject()
{
}
