
#include "BackBuffer.h"

CBackBuffer::CBackBuffer()
{}

bool CBackBuffer::Initialise(HWND _hWnd, int _iWidth, int _iHeight)
{
	m_hWnd = _hWnd;
	m_iWidth = _iWidth;
	m_iHeight = _iHeight;

	HDC hWindowDC = ::GetDC(m_hWnd);
	m_BFDC = CreateCompatibleDC(hWindowDC);
	m_hBFBitmap = CreateCompatibleBitmap(hWindowDC, m_iWidth, m_iHeight);
	ReleaseDC(m_hWnd, hWindowDC);

	m_hOldBitmap = static_cast<HBITMAP>(SelectObject(m_BFDC, m_hBFBitmap));

	HBRUSH brushWhite = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));

	return(0);
}

void CBackBuffer::Clear()
{
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(GetBFDC(), GetStockObject(WHITE_BRUSH)));
	Rectangle(GetBFDC(), 0, 0, GetWidth(), GetHeight());
	SelectObject(GetBFDC(), oldBrush);
}

void CBackBuffer::Present()
{
	HDC hWndDC = ::GetDC(m_hWnd);
	BitBlt(hWndDC, 0, 0, m_iWidth, m_iHeight, m_BFDC, 0, 0, SRCCOPY);
	ReleaseDC(m_hWnd, hWndDC);
}

CBackBuffer::~CBackBuffer()
{
	SelectObject(m_BFDC, m_hOldBitmap);
	DeleteObject(m_hBFBitmap);
	DeleteObject(m_BFDC);
}

HDC CBackBuffer::GetBFDC() const
{
	return (m_BFDC);
}

int CBackBuffer::GetHeight() const
{

	return(m_iHeight);
}
int CBackBuffer::GetWidth() const
{

	return(m_iWidth);

}