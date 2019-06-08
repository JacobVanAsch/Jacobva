#include "Canvas.h"
#include <windows.h>
#include <windowsx.h>

Canvas::Canvas()
{
	m_pBackBuffer = nullptr;
}

bool Canvas::Initialise(HWND _hwnd, int _iWidth, int _iHeight)
{
	if (m_pBackBuffer == nullptr)
	{
		m_pBackBuffer = new CBackBuffer;
		m_pBackBuffer->Initialise(_hwnd, _iWidth, _iHeight);
		return(true);
	}
	return(false);
}

CBackBuffer* Canvas::GetBackBuffer()
{
	return m_pBackBuffer;
}

bool Canvas::Draw(HDC _hdc)
{
	m_pBackBuffer->Clear();

	std::vector<BitMaps*>::iterator BitMapIter = m_vecBitMaps.begin();
	std::vector<CRectangle*>::iterator RectIter = m_vecRect.begin();
	
	while (BitMapIter != m_vecBitMaps.end())
	{
		(*BitMapIter)->AddBitMap(_hdc);
		BitMapIter++;
	}
	while (RectIter != m_vecRect.end())
	{
		(*RectIter)->Draw(_hdc);
		RectIter++;
	}

	m_pBackBuffer->Present();
	return(true);
}

void Canvas::Save(HWND _hwnd)
{

}

void Canvas::AddShape(BitMaps* shape)
{
	m_vecBitMaps.push_back(shape);
}

void Canvas::AddRect(CRectangle* shape)
{
	m_vecRect.push_back(shape);
}


