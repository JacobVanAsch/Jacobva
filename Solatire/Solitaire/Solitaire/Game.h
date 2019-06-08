#pragma once
#include <vector>
#include <windows.h>
#include <windowsx.h>
#include "CRectangle.h"
#include "Canvas.h"
#include "BitMaps.h"
#include "Card.h"

using namespace std;

class Game :public Card
{
public:
	Game();
	~Game();

	void FlipMech(int FlipStack);
	//assign id to each card to render bitmaps off of when called and then shuffle
	//after shuffle allocate to the stacks
	void ShuffleDeck(Card* CardID);
	void AllocateStacks(Card* CardID);
	void startGame(Card* CardID);
	void setBoard(CRectangle* Rect, Canvas* g_pCanvas, BitMaps* BM, HINSTANCE hInstance, Card* CardID );
	void Deck(Card* CardID);

	vector<int> m_Hearts;
	vector<int> m_Clubs;
	vector<int> m_Spades;
	vector<int> m_Diamonds;
	CRectangle* Rect;
	Canvas* g_pCanvas;
	BitMaps* BM;
	HINSTANCE hInstance;
	//int Cards;

};

