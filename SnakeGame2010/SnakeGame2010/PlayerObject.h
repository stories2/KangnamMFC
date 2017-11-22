#pragma once

#include "GameObject.h"
#include <cstring>

using namespace std;

class PlayerObject : public GameObject
{

public:
	PlayerObject(Position playerPosition, CString filePath, int direction);
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
	void Draw(CPaintDC &cPaintDc, CRect &rect, CDC &memDC);
	~PlayerObject();
};

