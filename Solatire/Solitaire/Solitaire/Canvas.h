#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <windows.h>
#include <windowsx.h>
#include <vector>
#include "BitMaps.h"
#include "CRectangle.h"
#include "backBuffer.h"



class BitMaps;
class CBackBuffer;

class Canvas
{
public:
	Canvas();
	~Canvas() = default;
	bool Initialise(HWND _hwnd, int _iWidth, int _iHeight);
	CBackBuffer* GetBackBuffer();
	bool Draw(HDC _hdc);
	void Save(HWND _hwnd);
	void AddShape(BitMaps*);
	void AddRect(CRectangle*);

private:
	CBackBuffer* m_pBackBuffer; // A canvas has a backbuffer.
	std::vector<BitMaps*> m_vecBitMaps;
	std::vector<CRectangle*> m_vecRect;
	

};

#endif
