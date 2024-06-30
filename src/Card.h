#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    public:
        enum Suit {
            Hearts,
            Diamonds,
            Clubs,
            Spades
        };

        enum Rank {
            Ace = 1,
            Two,
            Three,
            Four,
            Five,
            Six,
            Seven,
            Eight,
            Nine,
            Ten,
            Jack,
            Queen,
            King
        };

        Card(Rank rank, Suit suit);
        
        ~Card();

        Rank getRank() const;
        Suit getSuit() const;

        std::string toString() const;

    private:
        Rank rank;
        Suit suit;
};

#endif