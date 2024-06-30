#ifndef HAND_H

#include <vector>
#include <stdexcept>
#include "Card.h"

template <std::size_t N>
class Hand {
    public:
        Hand();

        void addCard(const Card& card);

        Card getCard(std::size_t index) const;

        std::size_t getSize() const;

        std::string toString() const;

        std::string getTwoCardHandRanking() const;

        std::string getFiveCardHandRanking() const;
        
    private:
        std::vector<Card> cards;
        
        bool isStraightFlush() const;
        bool isFourOfAKind() const;
        bool isFullHouse() const;
        bool isFlush() const;
        bool isStraight() const;
        bool isThreeOfAKind() const;
        bool isTwoPair() const;
        bool isOnePair() const;
        bool getHighCard() const;
    };

#endif
