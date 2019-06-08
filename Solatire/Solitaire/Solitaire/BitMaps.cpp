#include "BitMaps.h"

BitMaps::BitMaps(int CardID, int xPos, int yPos, HINSTANCE hInstance)
{
	m_CardID = CardID;
	m_xPos = xPos;
	m_yPos = yPos;
	m_hInstance = hInstance;
}


void BitMaps::SetStartX(int _iStartX)
{
	//StartX = _iStartX;
}

void BitMaps::SetStartY(int _iStartY)
{
	//StartY = _iStartY;
}

bool BitMaps::AddBitMap(HDC hdc)
{
	HBITMAP hBitmap;
	hBitmap = LoadBitmap(m_hInstance, MAKEINTRESOURCE(m_CardID));
	if (hBitmap == NULL)
	{
		::MessageBox(NULL, L"Load Image Failed", L"Error", MB_OK);
		return false;
	}

	HDC hLocalDC;
	hLocalDC = ::CreateCompatibleDC(hdc);
	if (hLocalDC == NULL)
	{
		::MessageBox(NULL, L"CreateCompatibleDC Failed", L"Error", MB_OK);
		return false;
	}

	BITMAP qBitmap;
	int iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
	if (!iReturn)
	{
		::MessageBox(NULL, L"GetObject Failed", L"Error", MB_OK);
		return false;
	}

	HBITMAP hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
	if (hOldBmp == NULL)
	{
		::MessageBox(NULL, L"SelectObject Failed", L"Error", MB_OK);
		return false;
	}

	BOOL qRetBlit = ::BitBlt(hdc, m_xPos, m_yPos, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY);
	if (!qRetBlit)
	{
		::MessageBox(NULL, L"BitBlt Failed", L"Error", MB_OK);
		return false;
	}

	::SelectObject(hLocalDC, hOldBmp);
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);
	return(true);
}