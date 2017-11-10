#pragma once

#include "GameObject.h"

class PlayerObect : public GameObject
{

public:
	PlayerObect(Position playerPosition, CImage playerImage, int direction);
	void SetPosition(Position position);
	Position GetPosition();
	void SetPlayerImage(CImage playerImage);
	CImage GetPlayerImage();
	void SetDirection(int direction);
	int GetDirection();
	void SetNextGameObject(GameObject *nextGameObject);
	GameObject* GetNextGameObject();
	GameObject* GetLastGameObject();
	void SetAnimeFrame(int animeFrame);
	int GetAnimeFrame();
	void Draw();
	~PlayerObect();
};

