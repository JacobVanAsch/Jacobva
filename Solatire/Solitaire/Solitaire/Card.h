#pragma once
#include <vector>

using namespace std;

class Card
{
public:
	Card();
	~Card() = default;

	void CardID();
	bool isFlipped(int CardID);

	int m_CardID;
	bool m_isFlipped;
	vector<int> m_Deck;
	vector<int> m_FlipStack;
	vector<int> m_Stack_A;
	vector<int> m_Stack_B;
	vector<int> m_Stack_C;
	vector<int> m_Stack_D;
	vector<int> m_Stack_E;
	vector<int> m_Stack_F;
	vector<int> m_Stack_G;
};

