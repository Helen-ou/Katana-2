#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Player {
public:
    std::string role;
    int health;
    int honor;
    std::vector<std::string> hand;

    Player(std::string r, int h, int ho) : role(r), health(h), honor(ho) {}

    void displayInfo() {
        std::cout << "Role: " << role << "\tHealth: " << health << "\tHonor: " << honor << std::endl;
    }

    void displayHand() {
        std::cout << "Hand: ";
        for (const auto& card : hand) {
            std::cout << card << " ";
        }
        std::cout << std::endl;
    }
};

class Game {
private:
    std::vector<Player> players;
    std::vector<std::string> roles = {"Shogun", "Samurai", "Ronin", "Ninja"};
    std::vector<std::string> allCards = {
        "AttaqueRapide", "CeremonieDuThe", "CodeDuBushido", "Meditation",
        "CriDeGuerre", "JuJitsu", "Concentration", "Diversion", "Geisha", "Daimyo"
    };
    std::vector<std::string> deck;
    std::vector<std::string> discardPile;
    int currentPlayerIndex;

public:
    void setupGame(int numPlayers) {
        if (numPlayers >= 3 && numPlayers <= 7) {
            for (int i = 0; i < numPlayers; ++i) {
                players.push_back(Player(roles[i], 3, 0));
            }

            distributeHonorCodes(numPlayers);

            initializeDeck();
            std::random_shuffle(deck.begin(), deck.end());

            distributeCharacterCards();
        } else {
            std::cerr << "Invalid number of players. Must be between 3 and 7." << std::endl;
        }
    }

    void distributeHonorCodes(int numPlayers) {
        if (numPlayers >= 3 && numPlayers <= 7) {
            for (int i = 0; i < numPlayers; ++i) {
                if (roles[i] == "Shogun") {
                    players[i].honor = (numPlayers == 3) ? 2 : 1;
                } else if (roles[i] == "Samurai") {
                    players[i].honor = (numPlayers == 4) ? 2 : 1;
                } else if (roles[i] == "Ronin") {
                    players[i].honor = (numPlayers == 5) ? 2 : 3;
                } else if (roles[i] == "Ninja") {
                    players[i].honor = (numPlayers == 3) ? 1 : 2;
                }
            }
        }
    }

    void initializeDeck() {
        deck = allCards;
    }

    void distributeCharacterCards() {
        std::random_shuffle(deck.begin(), deck.end());

        for (auto& player : players) {
            player.characterCardHealth = 3; 
            player.honor = (player.role == "Shogun") ? 5 : 4;  
            // Ajouter le reste
        }
    }

    void distributeInitialCards() {
        // Distribue
        std::random_shuffle(allCards.begin(), allCards.end());
        int cardIndex = 0;

        for (auto& player : players) {
            player.hand.clear(); // Clear any existing cards
            for (int i = 0; i < getInitialCardCount(players.size(), cardIndex, i); ++i) {
                player.hand.push_back(allCards[cardIndex]);
                ++cardIndex;
            }
        }
    }

    void startTurn() {
        Player& currentPlayer = players[currentPlayerIndex];

        if (currentPlayer.health == 0) {
            currentPlayer.health = currentPlayer.characterCardHealth;  // Recover all health
        }

        drawCards(currentPlayer);

        playCards(currentPlayer);

        discardExcessCards(currentPlayer);

        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    void drawCards(Player& player) {
        for (int i = 0; i < 2; ++i) {
            if (!deck.empty()) {
                player.hand.push_back(deck.back());
                deck.pop_back();
            } else {
                loseHonorPoints(1);
                refillDeck();
                if (!deck.empty()) {
                    player.hand.push_back(deck.back());
                    deck.pop_back();
                }
            }
        }
    }

    void refillDeck() {
        if (!discardPile.empty()) {
            std::cout << "Refilling the deck from the discard pile." << std::endl;

            std::random_shuffle(discardPile.begin(), discardPile.end());
            deck.insert(deck.end(), discardPile.begin(), discardPile.end());
            discardPile.clear();
        }
    }

    void loseHonorPoints(int points) {
        for (auto& player : players) {
            player.honor = std::max(0, player.honor - points);
        }
    }

    void playCards(Player& player) {
        std::cout << "Player " << player.role << "'s turn. Hand: ";
        for (const auto& card : player.hand) {
            std::cout << card << " ";
        }
        std::cout << std::endl;

        if (!player.hand.empty()) {
            std::string playedCard = player.hand.front();

            if (playedCard == "Concentration") {
                concentration(player);
            } else if (playedCard == "CriDeGuerre") {
                criDeGuerre(player);
            } else if (playedCard == "Daimyo") {
                daimyo(player);
            } else if (playedCard == "Diversion") {
                diversion(player);
            } else if (playedCard == "Geisha") {
                geisha(player);
            } else if (playedCard == "Meditation") {
                meditation(player);
            } else if (playedCard == "JuJitsu") {
                juJitsu(player);
            }
            player.hand.erase(player.hand.begin());
        }
    }


    void discardExcessCards(Player& player) {
        while (player.hand.size() > 7) {
            discardPile.push_back(player.hand.back());
            player.hand.pop_back();
        }
    }

     void attaqueRapide(Player& player) {
        std::cout << "Executing Attaque Rapide effect for " << player.role << "." << std::endl;

        int attaqueRapideCount = std::count(player.hand.begin(), player.hand.end(), "AttaqueRapide");

        player.attackDamage += attaqueRapideCount;
    }

    void ceremonieDuThe(Player& player) {
        std::cout << "Executing Cérémonie du Thé effect for " << player.role << "." << std::endl;

        for (int i = 0; i < 3; ++i) {
            drawCard(player);
        }

        for (Player& otherPlayer : players) {
            if (&otherPlayer != &player) {
                drawCard(otherPlayer);
            }
        }
    }

    void codeDuBushido(Player& player) {
        std::cout << "Executing Code du Bushido effect for " << player.role << "." << std::endl;

        std::string flippedCard = drawCard();

        if (isWeapon(flippedCard)) {
            discardWeapon(player);
            passCodeDuBushido(player);
        } else {
            passCodeDuBushido(player);
        }
    }

    void concentration(Player& player) {
        std::cout << "Executing Concentration effect for " << player.role << "." << std::endl;
        player.additionalWeaponsPerTurn += 1;
    }

    void criDeGuerre(Player& player) {
    std::cout << "Executing Cri de Guerre effect for " << player.role << "." << std::endl;
    
    for (auto& otherPlayer : players) {
        if (&otherPlayer != &player && !otherPlayer.isAtTerre()) {
            std::cout << otherPlayer.role << ", discard 1 parry or lose 1 health? (parry/health): ";
            std::string choice;
            std::cin >> choice;

            if (choice == "parry") {
                discardParry(otherPlayer);
            } else {
                otherPlayer.health -= 1;
                std::cout << otherPlayer.role << " loses 1 health." << std::endl;
            }
        }
    }
}

void daimyo(Player& player) {
    std::cout << "Executing Daimyo effect for " << player.role << "." << std::endl;

    drawCard(player);
    drawCard(player);
}

void diversion(Player& player) {
    std::cout << "Executing Diversion effect for " << player.role << "." << std::endl;

    for (auto& otherPlayer : players) {
        if (&otherPlayer != &player && !otherPlayer.hand.empty()) {
            std::random_shuffle(otherPlayer.hand.begin(), otherPlayer.hand.end());
            std::string drawnCard = otherPlayer.hand.back();
            otherPlayer.hand.pop_back();

            player.hand.push_back(drawnCard);

            std::cout << player.role << " draws 1 card from " << otherPlayer.role << "'s hand." << std::endl;
            break;  
        }
    }
}

void geisha(Player& player) {
    std::cout << "Executing Geisha effect for " << player.role << "." << std::endl;

    std::cout << "Choose an action for Geisha: (discard_permanent/discard_random_card): ";
    std::string choice;
    std::cin >> choice;

    if (choice == "discard_permanent") {
        discardPermanent(player);
    } else if (choice == "discard_random_card") {
        discardRandomCardFromOtherPlayer(player);
    }
}

void discardParry(Player& player) {
    auto it = std::find(player.hand.begin(), player.hand.end(), "Parade");
    if (it != player.hand.end()) {
        player.hand.erase(it);
        std::cout << player.role << " discards 1 parry." << std::endl;
    } else {
        std::cout << player.role << " doesn't have a parry to discard." << std::endl;
    }
}


int main() {
    std::srand(std::time(0));

    Game game;
    game.setupGame(4);

    game.distributeInitialCards();

    for (int turn = 1; turn <= 10; ++turn) { 
        std::cout << "========== Turn " << turn << " ==========" << std::endl;
        game.startTurn();
    }

    game.displayResults();

    return 0;
}
