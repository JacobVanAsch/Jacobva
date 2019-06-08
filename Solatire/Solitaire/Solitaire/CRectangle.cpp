#include <windows.h> 
#include <windowsx.h>
#include <iostream>
#include <wingdi.h>
#include "CRectangle.h"


CRectangle::CRectangle()
{}

CRectangle::CRectangle(int style, COLORREF _newColor, int _iStartX, int _iStartY, int _iEndX, int _iEndY, int _iWidth)
{
	m_iWidth = _iWidth;
	m_Color = _newColor;
	m_iStartX = _iStartX;
	m_iStartY = _iStartY;
	m_iEndX = _iEndX;
	m_iEndY = _iEndY;
	m_iPenStyle = style;


}

void CRectangle::Draw(HDC hdc)
{
	HPEN hLinePen = CreatePen(m_iPenStyle, m_iWidth, m_Color);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hLinePen);
	Rectangle(hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);
	SelectObject(hdc, hPenOld);
	DeleteObject(hLinePen);
}

COLORREF CRectangle::SetPenColor(COLORREF _newColor)
{
	return(_newColor);
}

int CRectangle::SetPenWidth(int _PenWidth)
{
	return(_PenWidth);
}