#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
    public:
        Deck();
        ~Deck();

        void shuffle();

        Card dealCard();

        bool isEmpty() const;

        void reset();

    private:
        std::vector<Card> cards;
        void initializeDeck();
};

#endif