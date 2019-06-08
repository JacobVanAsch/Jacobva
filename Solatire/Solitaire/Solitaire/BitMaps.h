#pragma once

#ifndef __STAMP_H__
#define __STAMP_H__

#include <Windows.h>
#include <windowsx.h>
#include <string>
#include "Card.h"


class BitMaps : public Card
{
	public:
		BitMaps(int CardID, int xPos, int yPos, HINSTANCE hInstance);
		//BitMaps();
		//BitMaps(HINSTANCE hInstance, wchar_t* filename, int, int);
		virtual ~BitMaps() = default;

		void SetStartX(int _iX);
		void SetStartY(int _iY);
		bool AddBitMap(HDC hdc);

	
		HBITMAP m_hBitMap;
		BITMAP m_bitmapStructure;
		int m_xPos;
		int m_yPos;
		HINSTANCE m_hInstance;

};

#endif