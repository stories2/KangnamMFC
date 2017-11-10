#include "stdafx.h"
#include "PlayerObect.h"


PlayerObect::PlayerObect(Position playerPosition, CImage playerImage, int direction)
{
	Position::SetPosition(playerPosition);
	GameObject::SetImage(playerImage);
	GameObject::SetDirection(direction);
	GameObject::SetAnimeFrame(ZERO);
}

void PlayerObect::SetPosition(Position position)
{
	Position::SetPosition(position);
}

Position PlayerObect::GetPosition()
{
	return Position::GetPosition();
}

void PlayerObect::SetPlayerImage(CImage playerImage)
{
	GameObject::SetImage(playerImage);
}

CImage PlayerObect::GetPlayerImage()
{
	return GameObject::GetImage();
}

void PlayerObect::SetDirection(int direction)
{
	GameObject::SetDirection(direction);
}

int PlayerObect::GetDirection()
{
	return GameObject::GetDirection();
}

void PlayerObect::SetNextGameObject(GameObject * nextGameObject)
{
	GameObject::SetNextGameObject(nextGameObject);
}

GameObject * PlayerObect::GetNextGameObject()
{
	return GameObject::GetNextGameObject();
}

GameObject * PlayerObect::GetLastGameObject()
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

void PlayerObect::SetAnimeFrame(int animeFrame)
{
	GameObject::SetAnimeFrame(animeFrame);
}

int PlayerObect::GetAnimeFrame()
{
	return GameObject::GetAnimeFrame();
}

void PlayerObect::Draw()
{
}

PlayerObect::~PlayerObect()
{
}
