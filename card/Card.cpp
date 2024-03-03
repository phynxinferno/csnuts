//
// Created by phoenix on 02/03/24.
//

#include "Card.h"
#include "string"

using namespace std;

namespace cardSystem {

    const string faces[] = {"Jester","Jack", "Queen", "King"};
    const string suits[] = {"suitles","diamond", "club", "spade", "heart"};

    class Card {
    public:
        unsigned int face, suit;
        Card(const unsigned int face, const unsigned int suit) {
            this->face = face;
            this->suit = suit;
        }
        Card() {
            face = (suit = 0);
        };
        Card(const Card &card) {
            *this = card;
        };
        string toString() {
            return ((face > 4) ? to_string(face - 3) : faces[face]) + " of " + suits[suit] + "s";
        }
        ostream& operator<<(ostream& stream) {
            stream << toString();
        }
    };

    Card BaseDeck[52];

    class Deck {
    public:
        static const unsigned int sizeOfDeck = 52;
        unsigned int currentCard = 0;
        Card* Contents[52] = {};
        Card* deal();
        bool moreCards() {
            return currentCard > 50;
        };
        Deck() {
            for(unsigned int i = 0; i < sizeOfDeck; i++) Contents[i] = &BaseDeck[i];
        };
        Card* DealCard() {
            return Contents[(currentCard++) - 1];
        }
        void shuffle() {
            for(unsigned int i = 0; i < sizeOfDeck; i++) {
                const unsigned int randPos = rand() % (sizeOfDeck - 1);
                swap(Contents[i], Contents[randPos + (int)(randPos >= i - 1)]);
            };
        }
    };

}