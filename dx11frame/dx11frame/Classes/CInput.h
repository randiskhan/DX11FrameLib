// CInput.h
// Declaration file for CInput.

#pragma once

#include "common.h"
#include <windows.h>

struct CInputData
{
	HWND	hwnd;

	CInputData()
	{
		hwnd = nullptr;
	}
};

// Class for all input logic and objects
class CInput
{
private:
	POINT		_mousePos;
	BYTE		_keysCurr[256];
	BYTE		_keysPrev[256];

	CInputData	_CInputData;

protected:

public:
	CInput(CInputData id);
	virtual ~CInput(void);

	bool		Init(void);
	bool		Update(void);
	void		Cleanup(void);

	void		SetMousePos(int x, int y);

	const PPOINT	GetMouseScreenPos(void);
	bool			IsMouseButtonLeftDown(void);
	bool			IsMouseButtonLeftUp(void);
	bool			IsMouseButtonRightDown(void);
	bool			IsMouseButtonRightUp(void);
	bool			IsMouseButtonLeftDownSinceLastFrame(void);
	bool			IsMouseButtonLeftUpSinceLastFrame(void);
	bool			IsMouseButtonRightDownSinceLastFrame(void);
	bool			IsMouseButtonRightUpSinceLastFrame(void);

	bool			IsKeyDown(int vk);
	bool			IsKeyUp(int vk);
	bool			IsKeyDownSinceLastFrame(int vk);
	bool			IsKeyUpSinceLastFrame(int vk);
};
