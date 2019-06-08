#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#pragma once

//	Library Includes
#include <windows.h>
#include <windowsx.h>


class CRectangle 
{
public:
	CRectangle(int style, COLORREF _PenColor, int _X, int _Y, int _EX, int _EY, int _width);
	CRectangle();
	virtual ~CRectangle() = default;

	void Draw(HDC _hdc);
	void SetFillColor(COLORREF _newColor);
	void SetPenStyle(int _iPenStyle);
	COLORREF SetPenColor(COLORREF _newColor);
	int SetPenWidth(int _PenWidth);

private:
	COLORREF m_iFillColor;
	int m_iPenStyle;
	COLORREF m_Color;
	int m_iWidth;
	int m_iStartX;
	int m_iStartY;
	int m_iEndX;
	int m_iEndY;

};

#endif