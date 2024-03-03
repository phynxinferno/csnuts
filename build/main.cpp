//
// Created by phoenix on 02/03/24.
//

#include "string"

using namespace std;

namespace cardSystem {

    const string faces[] = {"jester","jack", "queen", "king", "ace"};
    const string suits[] = {"suitles","diamond", "club", "spade", "heart"};

    class Card {
    public:
        unsigned int face, suit;
        Card(const unsigned int* face, const unsigned int* suit) {
            this->face = *face;
            this->suit = *suit;
        }
        Card() {
            face = (suit = 0);
        };
        Card(const Card &NewCard) {
            *this = NewCard;
        };
        string toString() const {
            return ((face > 4) ? to_string(face - 3) : faces[face]) + " of " + suits[suit] + "s";
        }
    };

    ostream& operator<<(ostream& stream, const Card &logged) {
        stream << logged.toString();
        return stream;
    }

    Card BaseDeck[52];

    class Deck {
    public:
        static const unsigned int sizeOfDeck = 52;
        unsigned int currentCard = 0;
        Card* Contents[52] = {};
        bool moreCards() {
            return currentCard > 50;
        };
        Deck() {
            for(unsigned int i = 0; i < sizeOfDeck; i++) Contents[i] = &BaseDeck[i];
        };
        Card* DealCard() {
            return Contents[(currentCard++)];
        }
        void shuffle() {
            for(unsigned int i = 0; i < sizeOfDeck; i++) {
                const unsigned int randPos = rand() % (sizeOfDeck - 1);
                swap(Contents[i], Contents[randPos + (int)(randPos >= i - 1)]);
            };
        }
    };

}

using namespace cardSystem;

#include "iostream"
#include "chrono"
#include "vector"
#include <cstring>

string getLine() {
    string input;
    cin >> input;
    return input;
}

void level3() {
    Deck* Cards = new Deck();
    Cards->shuffle();
    for(unsigned int i = 0; i < Cards->sizeOfDeck; i++) {
        cout << *Cards->DealCard() << endl;
    }
    delete Cards;
}

const Card* ReadErase(vector<Card*>* vect, const unsigned int index) {
    const Card* Erased = vect->at(index);
    vect->erase(vect->begin() + index);
    return Erased;
}

void level4() {
    cout << "Poker Game: Blackjack" << endl << "🗘 Shuffling deck..." << endl;
    Deck* TempDeck = new Deck();
    TempDeck->shuffle();
    vector<Card*> BjDeck;
    BjDeck.insert(BjDeck.end(),&TempDeck->Contents[0], &TempDeck->Contents[52]);
    delete TempDeck;
    cout << "🗊 Dealing..." << endl;
    const Card* DealerHand[] = { ReadErase(&BjDeck,rand() % 52),ReadErase(&BjDeck,rand() % 51)};
    cout << "🃟 The dealer's hand contains the hole and the " << *DealerHand[0] << "." << endl;
    cout << "🃟͢ The " << *ReadErase(&BjDeck, 0) << " was removed from the deck." << endl;
    unsigned int playerHand = 0;
    do {
        cout << "🏛 Your hand is currently worth " << playerHand << endl << "\tWould you like to [d]raw or [s]tand? [D/s]";
        if(BjDeck.size() != 0 && tolower(getLine()[0]) != 's') {
            const Card* Drawn = ReadErase(&BjDeck, rand() % BjDeck.size());
            if(Drawn->face == 4) playerHand += (playerHand > 10) ? 1 : 11;
            else playerHand += (Drawn->face > 4) ? Drawn->face - 3 : 10;
            cout << "🃟̟ You drew the " << *Drawn << endl;
            if(playerHand >= 21) {
                cout << ((playerHand == 21) ? "💰 Twenty-one! You win." : "☠ Bust! The house wins.") << endl;
                exit(0);
            }
        } else break;
    } while(true);
    cout << "🯅͏ You stood..." << endl << "🃟 The dealer had the " << *DealerHand[0] << " and the hole was " << *DealerHand[1] << "!" << endl;
    unsigned int dealerHand = 0;
    for(const Card* DealerCard : DealerHand) {
        if(DealerCard->face == 4) dealerHand += 11;
        else dealerHand += (DealerCard->face > 4) ? DealerCard->face - 3 : 10;
    }
    cout << ((playerHand > dealerHand) ? "💰 You win." : "☠ The house wins.") << endl;
}

int main(int argc, char** argv) {
    unsigned int offset;
    srand(chrono::system_clock::now().time_since_epoch().count());
    for(unsigned int i = 1; i < 5; i++) {
        offset = (i - 1) * 13;
        for(unsigned int j = 1; j < 14; j++) BaseDeck[offset + j - 1] = Card(&j,&i);
    }
    cout << "This program bundles the level [3] and level [4] versions of this project. Which would you like to run? [̺3/4]";
    if(getLine()[0] == '4') level4(); else level3();
}
