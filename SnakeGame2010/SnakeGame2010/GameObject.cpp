#include "stdafx.h"
#include "GameObject.h"
#include "LogManager.h"

GameObject::GameObject()
{
	Position::SetPosition(ZERO, ZERO);
	this->nextGameObject = nullptr;
	this->beforeGameObject = nullptr;
}

void GameObject::SetNextGameObject(GameObject * gameObject)
{
	this->nextGameObject = gameObject;
}

GameObject * GameObject::GetNextGameObject()
{
	return this->nextGameObject;
}

void GameObject::SetBeforeGameObject(GameObject *gameObject) 
{
	this->beforeGameObject = gameObject;
}

GameObject * GameObject::GetBeforeGameObject() 
{
	return this->beforeGameObject;
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

void GameObject::Draw(CPaintDC &cPaintDc, CRect &rect, CDC &memDC)
{
	if(objectImage != NULL) {

		CBitmap bitmap;
		bitmap.Attach(objectImage.Detach());
		//memDC.SelectObject(&image);
		memDC.SelectObject(&bitmap);
		//image.Draw(dc.GetSafeHdc(), 0, 0, 32, 32, 0, 0, 32, 32);
		//cPaintDc.BitBlt(0, 0, 32, 32, &memDC, 0, 0, SRCCOPY);
	}
	else {
		LogManager::PrintMessage(CString("GameObject"), CString("Draw"), CString("image is null"), LOG_LEVEL_WARN);
	}
}


GameObject::~GameObject()
{
	delete this->nextGameObject;
	objectImage.Destroy();
}
