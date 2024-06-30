#include "Card.h"

Card::Card(Rank r, Suit s): rank(r), suit(s) {}

Card::~Card() {}

Card::Rank Card::getRank() const {
    return rank;
}

Card::Suit Card::getSuit() const {
    return suit;
}

std::string Card::toString() const {
    std::string rankStr;
    switch (rank) {
        case Ace:   rankStr = "Ace"; break;
        case Two:   rankStr = "Two"; break;
        case Three: rankStr = "Three"; break;
        case Four:  rankStr = "Four"; break;
        case Five:  rankStr = "Five"; break;
        case Six:   rankStr = "Six"; break;
        case Seven: rankStr = "Seven"; break;
        case Eight: rankStr = "Eight"; break;
        case Nine:  rankStr = "Nine"; break;
        case Ten:   rankStr = "Ten"; break;
        case Jack:  rankStr = "Jack"; break;
        case Queen: rankStr = "Queen"; break;
        case King:  rankStr = "King"; break;
    }

    std::string suitStr;
    switch (suit) {
        case Hearts:   suitStr = "Hearts"; break;
        case Diamonds: suitStr = "Diamonds"; break;
        case Clubs:    suitStr = "Clubs"; break;
        case Spades:   suitStr = "Spades"; break;
    }

    return rankStr + " of " + suitStr;
}