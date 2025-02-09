#include "Hand.h"
#include "Deck.h"
#include <iostream>
#include <unordered_map>
#include <random>
#include <iomanip>

// Function to simulate dealing a two-card hand and then filling it to a five-card hand
template <std::size_t N>
void simulateTransition(std::unordered_map<std::string, std::unordered_map<std::string, int>>& transitionCount, int numSimulations) {
    for (int i = 0; i < numSimulations; ++i) {
        Deck deck;
        deck.shuffle();
        
        // Deal a two-card hand
        Hand<2> twoCardHand;
        twoCardHand.addCard(deck.dealCard());
        twoCardHand.addCard(deck.dealCard());
        
        // Evaluate the two-card hand ranking
        std::string twoCardRank = twoCardHand.getTwoCardHandRanking();
        
        // Deal remaining cards to form a five-card hand
        Hand<N> fiveCardHand;
        fiveCardHand.addCard(twoCardHand.getCard(0));
        fiveCardHand.addCard(twoCardHand.getCard(1));
        for (int j = 0; j < N - 2; ++j) {
            fiveCardHand.addCard(deck.dealCard());
        }
        
        // Evaluate the five-card hand ranking
        std::string fiveCardRank = fiveCardHand.getFiveCardHandRanking();
        
        // Update transition count
        transitionCount[twoCardRank][fiveCardRank]++;
    }
}

// Function to print transition probabilities
void printTransitionProbabilities(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& transitionCount, int numSimulations) {
    std::cout << "Transition Probability Matrix:" << std::endl;
    std::cout << std::setw(20) << "From / To |";
    
    // Print headers for two-card hand rankings
    for (const auto& entry : transitionCount) {
        std::cout << std::setw(15) << entry.first << "|";
    }
    std::cout << std::endl;
    
    // Print separator
    for (int i = 0; i < 20 + 15 * transitionCount.size(); ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
    
    // Print transition probabilities
    for (const auto& fromEntry : transitionCount) {
        std::cout << std::setw(20) << fromEntry.first << "|";
        for (const auto& toEntry : transitionCount) {
            int count = transitionCount.at(fromEntry.first).at(toEntry.first);
            double probability = static_cast<double>(count) / numSimulations;
            std::cout << std::setw(15) << std::fixed << std::setprecision(4) << probability << "|";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int numSimulations = 1000000; // Number of simulations to run
    std::unordered_map<std::string, std::unordered_map<std::string, int>> transitionCount;
    
    // Simulate transitions from a two-card hand to a five-card hand
    simulateTransition<5>(transitionCount, numSimulations);
    
    std::vector<std::string> allHandRankings = {"High Card", "One Pair", "Two Pair", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush", "Royal Flush"};

    // Print headers for all possible hand rankings
    for (const auto& handRanking : allHandRankings) {
        std::cout << std::setw(15) << handRanking << "|";
    }
    std::cout << std::endl;

    // Print separator
    for (int i = 0; i < 20 + 15 * allHandRankings.size(); ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;

    // Print transition probabilities
    for (const auto& fromRanking : allHandRankings) {
        std::cout << std::setw(20) << fromRanking << "|";
        for (const auto& toRanking : allHandRankings) {
            int count = 0;
            if (transitionCount.count(fromRanking) > 0 && transitionCount.at(fromRanking).count(toRanking) > 0) {
                count = transitionCount.at(fromRanking).at(toRanking);
            }
            double probability = static_cast<double>(count) / numSimulations;
            std::cout << std::setw(15) << std::fixed << std::setprecision(4) << probability << "|";
        }
        std::cout << std::endl;
    }

    
    return 0;
}