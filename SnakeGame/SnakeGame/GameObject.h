#pragma once

#include "Position.h"

class GameObject : public Position
{
	GameObject *nextGameObject;
	int direction, animeFrame;
	CImage objectImage;
public:
	GameObject();
	void SetNextGameObject(GameObject *gameObject);
	GameObject *GetNextGameObject();
	void DeleteNextGameObject();
	void SetDirection(int direction);
	int GetDirection();
	void SetAnimeFrame(int animeFrame);
	int GetAnimeFrame();
	void SetImage(CImage objectImage);
	CImage GetImage();
	~GameObject();
};