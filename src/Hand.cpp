#include "Hand.h"
#include <sstream>
#include <algorithm>

template <std::size_t N>
Hand<N>::Hand() {

}

template <std::size_t N>
void Hand<N>::addCard(const Card& card) {
    if (cards.size() >= N) {
        throw std::out_of_range("Hand is full, cannot add more cards.");
    }
    cards.push_back(card);
}

template <std::size_t N>
Card Hand<N>::getCard(std::size_t index) const {
    if (index >= cards.size()) {
        throw std::out_of_range("Index out of range.");
    }
    return cards[index];
}

template <std::size_t N>
std::size_t Hand<N>::getSize() const {
    return cards.size();
}

template <std::size_t N>
std::string Hand<N>::toString() const {
    std::stringstream ss;
    ss << "Hand with " << cards.size() << " cards: ";
    for (const auto& card : cards) {
        ss << card.toString() << " ";
    }
    return ss.str();
}

template <std::size_t N>
std::string Hand<N>::getTwoCardHandRanking() const {
    bool isFlush = cards[0].getSuit() == cards[1].getSuit();
    bool isStraight = (cards[0].getRank() == cards[1].getRank() - 1) || (cards[1].getRank() == cards[0].getRank() - 1);

    if (isFlush && isStraight) {
        return "Straight Flush";
    } else if (isFlush) {
        return "Flush";
    } else if (cards[0].getRank() == cards[1].getRank()) {
        return "One Pair";
    } else {
        return "High Card";
    }
}

template <std::size_t N>
std::string Hand<N>::getFiveCardHandRanking() const {
    if (N != 5) {
        throw std::logic_error("getFiveCardHandRanking() can only be called for 5-card hands.");
    }

    if (isStraightFlush()) {
        return "Straight Flush";
    } else if (isFourOfAKind()) {
        return "Four of a Kind";
    } else if (isFullHouse()) {
        return "Full House";
    } else if (isFlush()) {
        return "Flush";
    } else if (isStraight()) {
        return "Straight";
    } else if (isThreeOfAKind()) {
        return "Three of a Kind";
    } else if (isTwoPair()) {
        return "Two Pair";
    } else if (isOnePair()) {
        return "One Pair";
    } else {
        return "High Card";
    }
}

template <std::size_t N>
bool Hand<N>::isStraightFlush() const {
    return isStraight() && isFlush();
}

template <std::size_t N>
bool Hand<N>::isFourOfAKind() const {
    std::vector<int> ranks;
    for (const auto& card : cards) {
        ranks.push_back(card.getRank());
    }
    std::sort(ranks.begin(), ranks.end());
    return (ranks[0] == ranks[1] && ranks[1] == ranks[2] && ranks[2] == ranks[3]) || (ranks[1] == ranks[2] && ranks[2] == ranks[3] && ranks[3] == ranks[4]);
}

template <std::size_t N>
bool Hand<N>::isFullHouse() const {
    std::vector<int> ranks;
    for (const auto& card : cards) {
        ranks.push_back(card.getRank());
    }
    std::sort(ranks.begin(), ranks.end());
    return (ranks[0] == ranks[1] && ranks[1] == ranks[2] && ranks[3] == ranks[4]) || (ranks[0] == ranks[1] && ranks[2] == ranks[3] && ranks[3] == ranks[4]);
}

template <std::size_t N>
bool Hand<N>::isFlush() const {
    char suit = cards[0].getSuit();
    for (const auto& card : cards) {
        if (card.getSuit() != suit) {
            return false;
        }
    }
    return true;
}

template <std::size_t N>
bool Hand<N>::isStraight() const {
    std::vector<int> ranks;
    for (const auto& card : cards) {
        ranks.push_back(card.getRank());
    }
    std::sort(ranks.begin(), ranks.end());
    return (ranks[0] + 1 == ranks[1] && ranks[1] + 1 == ranks[2] &&
            ranks[2] + 1 == ranks[3] && ranks[3] + 1 == ranks[4]);
}

template <std::size_t N>
bool Hand<N>::isThreeOfAKind() const {
    std::vector<int> ranks;
    for (const auto& card : cards) {
        ranks.push_back(card.getRank());
    }
    std::sort(ranks.begin(), ranks.end());
    return (ranks[0] == ranks[1] && ranks[1] == ranks[2]) || (ranks[1] == ranks[2] && ranks[2] == ranks[3]) || (ranks[2] == ranks[3] && ranks[3] == ranks[4]);
}

template <std::size_t N>
bool Hand<N>::isTwoPair() const {
    std::vector<int> ranks;
    for (const auto& card : cards) {
        ranks.push_back(card.getRank());
    }
    std::sort(ranks.begin(), ranks.end());
    return (ranks[0] == ranks[1] && ranks[2] == ranks[3]) || (ranks[0] == ranks[1] && ranks[3] == ranks[4]) || (ranks[1] == ranks[2] && ranks[3] == ranks[4]);
}

template <std::size_t N>
bool Hand<N>::isOnePair() const {
    std::vector<int> ranks;
    for (const auto& card : cards) {
        ranks.push_back(card.getRank());
    }
    std::sort(ranks.begin(), ranks.end());
    return (ranks[0] == ranks[1]) || (ranks[1] == ranks[2]) || (ranks[2] == ranks[3]) || (ranks[3] == ranks[4]);
}

template <std::size_t N>
bool Hand<N>::getHighCard() const {
    return true;
}

template class Hand<2>;
template class Hand<5>;