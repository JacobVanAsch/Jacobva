#include "Card.h"
#include "game.h"



Card::Card()
{
}

void Card::CardID()
{
	int o = 0;
	for (int i = 158; i <= 209; i++ )
	{
		m_CardID = i;
		m_Deck.push_back(m_CardID);
		o++;
	}
}

bool Card::isFlipped(int CardID)
{
	return(false);
}