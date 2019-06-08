#include <Windows.h>
#include <Windowsx.h>
#include "Canvas.h"
#include "BackBuffer.h"
#include "resource.h"
#include "Game.h"
#include "CRectangle.h"
#include <stack>
#include "Card.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"

HINSTANCE g_hInstance;
Canvas* g_pCanvas;
HMENU g_hMenu;
HWND CursorPosField;
HWND hwnd;  // Generic window handle.  
BitMaps* BM;
Game* Start;
Game* SetBoard;
Card* CardID;
//int i = 0;
//int a = 0;
//int b = 0;
//int c = 0;
//int d = 0;
//int e = 0;
//int f = 0;
//int o = 0;
CRectangle* Rect;
//int Penstyle = PS_SOLID;
//COLORREF qLineColor = RGB(0, 0, 0);
//int PenWidth = 1;

void GameLoop()
{
	
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.

	int selectedTool = NULL;
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.
		g_pCanvas = new Canvas();
		CardID = new Card();
		Start = new Game();
		
		g_pCanvas->Initialise(_hwnd, 1920, 1080);
		CardID->CardID();
		Start->startGame(CardID);

		SetBoard->setBoard(Rect, g_pCanvas, BM, g_hInstance, CardID);
		
		// Return Success.
		return (0);
	}
	break;

	case WM_PAINT:
	{
		hdc = BeginPaint(_hwnd, &ps);
		
		
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());

		EndPaint(_hwnd, &ps);
		// Return Success.
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
			case ID_FILE_EXIT:
			{
				PostQuitMessage(0);
				break;
			}
			case ID_HELP_ABOUT:
			{
				MessageBox(_hwnd, L"This Solitaire game was developed by Jacob van Asch", L"Author Information", MB_OK | MB_ICONINFORMATION);
				break;
			}
		default:
			break;
		}
		return(0);
	}
	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);
		// Return success.
		return (0);
	}
	default:
		break;
	} // End switch.	// Process any messages that we did not take care of...
	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}
int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	MSG msg;             // Generic message.

	g_hInstance = _hInstance;
	// First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
	static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));
	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"Solitaire",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100,                    // Initial x,y.
		750, 700,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			// Translate any accelerator keys.
			TranslateMessage(&msg);
			// Send the message to the window proc.
			DispatchMessage(&msg);
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}