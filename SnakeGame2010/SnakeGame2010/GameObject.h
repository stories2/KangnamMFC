#pragma once

#include "Position.h"

class GameObject : public Position
{
	GameObject *nextGameObject, *beforeGameObject;
	int direction, animeFrame;
public:
	CImage objectImage;
public:

	GameObject();
	void SetNextGameObject(GameObject *gameObject);
	GameObject *GetNextGameObject();
	void SetBeforeGameObject(GameObject *gameObject);
	GameObject *GetBeforeGameObject();
	void DeleteNextGameObject();
	void SetDirection(int direction);
	int GetDirection();
	void SetAnimeFrame(int animeFrame);
	int GetAnimeFrame();
	void SetImage(CImage objectImage);
	CImage GetImage();
	void Draw(CPaintDC &cPaintDc, CRect &rect, CDC &memDC);
	~GameObject();
};