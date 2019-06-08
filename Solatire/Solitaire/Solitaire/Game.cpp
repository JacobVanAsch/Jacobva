#include "Game.h"
#include <windows.h>
#include <windowsx.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include "Canvas.h"
#include <random>
#include <chrono>


using namespace std;

Game::Game()
{
	
}

Game::~Game()
{
}

void Game::Deck(Card* CardID)
{
	

}

void Game::ShuffleDeck(Card* CardID)
{
	auto rng = default_random_engine{};
	shuffle(CardID->m_Deck.begin(), CardID->m_Deck.end(), rng);
}

void Game::AllocateStacks(Card* CardID)
{
	int i = 0;
	int c = 0;
	for (i = i; i <= 0 + c; i++)
	{
		CardID->m_Stack_A.push_back(CardID->m_Deck.back());
		CardID->m_Deck.pop_back();
	}
	c = i;
	
	for (i = i; i <= 1 + c; i++)
	{
		CardID->m_Stack_B.push_back(CardID->m_Deck.back());
		CardID->m_Deck.pop_back();
	}
	c = i;
	
	for (i = i; i <= 2 + c; i++)
	{
		CardID->m_Stack_C.push_back(CardID->m_Deck.back());
		CardID->m_Deck.pop_back();
		
	}
	c = i;
	
	for (i = i; i <= 3 + c; i++)
	{
		CardID->m_Stack_D.push_back(CardID->m_Deck.back());
		CardID->m_Deck.pop_back();
		
	}
	c = i;
	
	for (i = i; i <= 4 + c; i++)
	{
		CardID->m_Stack_E.push_back(CardID->m_Deck.back());
		CardID->m_Deck.pop_back();
		
	}
	c = i;
	
	for (i = i; i <= 5 + c; i++)
	{
		CardID->m_Stack_F.push_back(CardID->m_Deck.back());
		CardID->m_Deck.pop_back();
		
	}
	c = i;
	
	for (i = i; i <= 6 + c; i++)
	{

		CardID->m_Stack_G.push_back(CardID->m_Deck.back());
		CardID->m_Deck.pop_back();

		
	}
	c = i;
	
	for (i = i; i <= 23 + c; i++)
	{
		CardID->m_FlipStack.push_back(CardID->m_Deck.back());
		CardID->m_Deck.pop_back();
	}

}

void Game::startGame(Card* CardID)
{
	ShuffleDeck(CardID);
	AllocateStacks(CardID);
}

void Game::setBoard(CRectangle* Rect, Canvas* g_pCanvas, BitMaps* BM, HINSTANCE hInstance, Card* CardID)
{
	int XPos = 60;
	int YPos = 15;
	int StartX = 140;
	int StartY = 15;
	int EndX = 210;
	int EndY = 110;
	int Penstyle = PS_SOLID;
	COLORREF qLineColor = RGB(0, 0, 0);
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int o = 0;
	int PenWidth = 1;

	g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
	BM = new BitMaps(CardID->m_FlipStack.back(), XPos, YPos, hInstance);
	CardID->m_FlipStack.pop_back();
	g_pCanvas->AddShape(BM);
	BM->AddBitMap(g_pCanvas->GetBackBuffer()->GetBFDC());

	//deck
	g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
	Rect = new CRectangle(Penstyle, qLineColor, StartX, StartY, EndX, EndY, PenWidth);
	g_pCanvas->AddRect(Rect);
	Rect->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());

	//stack 7
	XPos = 60;
	YPos = 120;
	for (i = i; i <= 6; i++)
	{
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		BM = new BitMaps(CardID->m_Stack_G.back(), XPos, YPos, hInstance);
		CardID->m_Stack_G.pop_back();
		g_pCanvas->AddShape(BM);
		BM->AddBitMap(g_pCanvas->GetBackBuffer()->GetBFDC());
		YPos += 10;
	}
	//stack 6
	XPos = 140;
	YPos = 120;


	for (a = a; a <= 5; a++)
	{
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		BM = new BitMaps(CardID->m_Stack_F.back(), XPos, YPos, hInstance);
		CardID->m_Stack_F.pop_back();
		g_pCanvas->AddShape(BM);
		BM->AddBitMap(g_pCanvas->GetBackBuffer()->GetBFDC());
		YPos += 10;

	}

	//stack 5
	XPos = 220;
	YPos = 120;
	for (b = b; b <= 4; b++)
	{
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		BM = new BitMaps(CardID->m_Stack_E.back(), XPos, YPos, hInstance);
		CardID->m_Stack_E.pop_back();
		g_pCanvas->AddShape(BM);
		BM->AddBitMap(g_pCanvas->GetBackBuffer()->GetBFDC());
		YPos += 10;

	}

	//stack 4
	XPos = 300;
	YPos = 120;
	for (c = c; c <= 3; c++)
	{
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		BM = new BitMaps(CardID->m_Stack_D.back(), XPos, YPos, hInstance);
		CardID->m_Stack_D.pop_back();
		g_pCanvas->AddShape(BM);
		BM->AddBitMap(g_pCanvas->GetBackBuffer()->GetBFDC());
		YPos += 10;

	}

	//stack 3
	XPos = 380;
	YPos = 120;
	for (d = d; d <= 2; d++)
	{
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		BM = new BitMaps(CardID->m_Stack_C.back(), XPos, YPos, hInstance);
		CardID->m_Stack_C.pop_back();
		g_pCanvas->AddShape(BM);
		BM->AddBitMap(g_pCanvas->GetBackBuffer()->GetBFDC());
		YPos += 10;

	}

	//stack 2
	XPos = 460;
	YPos = 120;
	for (e = e; e <= 1; e++)
	{
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		BM = new BitMaps(CardID->m_Stack_B.back(), XPos, YPos, hInstance);
		CardID->m_Stack_B.pop_back();
		g_pCanvas->AddShape(BM);
		BM->AddBitMap(g_pCanvas->GetBackBuffer()->GetBFDC());
		YPos += 10;

	}
	//stack 1
	XPos = 540;
	YPos = 120;
	for (f = f; f <= 0; f++)
	{
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		BM = new BitMaps(CardID->m_Stack_A.back(), XPos, YPos, hInstance);
		CardID->m_Stack_A.pop_back();
		g_pCanvas->AddShape(BM);
		BM->AddBitMap(g_pCanvas->GetBackBuffer()->GetBFDC());
		YPos += 10;

	}

	//empty stacks for suites
	StartX = 300;
	StartY = 15;
	EndX = 370;
	EndY = 110;
	for (o = o; o <= 3; o++)
	{
		g_pCanvas->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		Rect = new CRectangle(Penstyle, qLineColor, StartX, StartY, EndX, EndY, PenWidth);
		g_pCanvas->AddRect(Rect);
		Rect->Draw(g_pCanvas->GetBackBuffer()->GetBFDC());
		StartX += 80;
		EndX += 80;
	}
}