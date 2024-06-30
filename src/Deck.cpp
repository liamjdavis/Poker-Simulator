#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>

Deck::Deck() {
    initializeDeck();
}

Deck::~Deck() {}

void Deck::initializeDeck() {
    cards.clear();

    for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
        for (int rank = Card::Ace; rank <= Card::King; ++rank) {
            cards.emplace_back(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
        }
    }
}

void Deck::shuffle() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

Card Deck::dealCard() {
    if (!cards.empty()) {
        Card dealtCard = cards.back();
        cards.pop_back();
        return dealtCard;
    } else {
        throw std::out_of_range("No cards left");
    }
}

bool Deck::isEmpty() const {
    return cards.empty();
}

void Deck::reset() {
    initializeDeck();
    shuffle();
}