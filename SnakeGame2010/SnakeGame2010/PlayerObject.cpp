#include "stdafx.h"
#include "PlayerObject.h"
#include "LogManager.h"


PlayerObject::PlayerObject(Position playerPosition, CString resourcePath, int direction)
{
	Position::SetPosition(playerPosition);
	/*CImage playerImage;
	playerImage.Load(resourcePath);
	if (playerImage != NULL) {
		LogManager::PrintMessage(CString("PlayerObject"), CString("PlayerObject"), CString("image loaded successfully: ") + resourcePath, LOG_LEVEL_INFO);
	}
	else {
		LogManager::PrintMessage(CString("PlayerObject"), CString("PlayerObject"), CString("the image is wrong"), LOG_LEVEL_WARN);
	}
	GameObject::SetImage(playerImage);*/
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

void PlayerObject::Draw(CPaintDC &cPaintDc, CRect &rect, CDC &memDC)
{
	//GameObject::Draw(cPaintDc, rect, memDC);
}
PlayerObject::~PlayerObject()
{
}
