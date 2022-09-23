#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// Prototypes

void game(int);
void menu();
bool playAgain(int);


class Player
{
public:
    int balance = 100;
    int hitOrStand;
    int playerCard1, playerCard2, playerCard3;
    std::string name;
    void multiMenu();
    void multiPlayer(int balance);
};

// Driver

int main()
{
    int input;
    std::cout << "1. Single Player " << std::endl;
    std::cout << "2. Multiplayer " << std::endl;

    std::cin >> input;

    if (input == 1)
    {
        int balance = 100;
        menu();
        game(balance);
    }
    if (input == 2)
    {
        Player player;
        int multiBalance = 100;
        player.multiMenu();
        player.multiPlayer(multiBalance);
    }
}

// Multiplayer Module

void Player::multiMenu()
{
    std::cout << "================================" << std::endl;
    std::cout << "Welcome to Blackjack Multiplayer" << std::endl;
    std::cout << "================================" << std::endl;
}

void Player::multiPlayer(int balance)
{
    int input;
    std::cout << "Enter total number of player (MAX IS 4 MIN IS 2) " << std::endl;
    std::cin >> input;

    if (input == 2)
    {
        int bet1, bet2, dealerCard1, dealerCard2, dealerCard3{}, sumOfDealerCards;
        std::string input2, input3;
        Player player1;
        Player player2;
        std::cout << "Enter name for player 1 and player 2 " << std::endl;
        std::cin >> input2 >> input3;
        player1.name = input2;
        player2.name = input3;


        std::cout << "The balances for each player are: " << player1.name << ": $" << player1.balance << " and " << player2.name << ": $" << player2.balance << std::endl;

        do
        {
            std::cout << "Enter bet for " << player1.name << std::endl;
            std::cin >> bet1;
            std::cout << "Enter bet for " << player2.name << std::endl;
            std::cin >> bet2;
            if (bet1 > player1.balance || bet2 > player2.balance)
            {
                std::cout << "Someone has bet too much, please enter less than or equal to your bet amount " << std::endl;
            }
        } while (bet1 > player1.balance && bet2 > player2.balance);

        std::cout << "\n\n";

        player1.balance -= bet1;
        player2.balance -= bet2;

        std::cout << player1.name << " has bet $" << bet1 << std::endl;
        std::cout << player2.name << " has bet $" << bet2 << std::endl;

        std::cout << "\n\n";

        std::cout << player1.name << " balance is: " << "$" << player1.balance << std::endl;
        std::cout << player2.name << " balance is: " << "$" << player2.balance << std::endl;
        std::cout << std::endl;

        std::cout << "Dealer is dealing cards... " << std::endl;
        srand(time(NULL));
        player1.playerCard1 = rand() % 11 + 1;
        player1.playerCard2 = rand() % 11 + 1;
        player2.playerCard1 = rand() % 11 + 1;
        player2.playerCard2 = rand() % 11 + 1;

        int sumOfCards1 = player1.playerCard1 + player1.playerCard2;
        int sumOfCards2 = player2.playerCard1 + player2.playerCard2;

        std::cout << player1.name << " cards: " << player1.playerCard1 << " & " << player1.playerCard2 << " total " << sumOfCards1 << std::endl;
        std::cout << player2.name << " cards: " << player2.playerCard1 << " & " << player2.playerCard2 << " total " << sumOfCards2 << std::endl;

        do
        {
            std::cout << player1.name << " turn " << std::endl;
            std::cout << "1. Hit " << std::endl;
            std::cout << "2. Stand " << std::endl;
            std::cin >> player1.hitOrStand;

            if (player1.hitOrStand == 1)
            {
                player1.playerCard3 = rand() % 10 + 1;
                sumOfCards1 += player1.playerCard3;
                std::cout << player1.name << " cards are " << player1.playerCard1 << " & " << player1.playerCard2 << " & " << player1.playerCard3 << " total " << sumOfCards1 << std::endl;

                if (sumOfCards1 > 21)
                {
                    std::cout << player1.name << " has bust " << std::endl;
                    // CHANGE TO PLAYER2

                    std::cout << "\n\n";

                    do
                    {
                        std::cout << player2.name << " turn " << std::endl;
                        std::cout << "1. Hit " << std::endl;
                        std::cout << "2. Stand " << std::endl;
                        std::cin >> player2.hitOrStand;

                        if (player2.hitOrStand == 1)
                        {
                            player2.playerCard3 = rand() % 10 + 1;
                            sumOfCards2 += player2.playerCard3;
                            std::cout << player2.name << " cards are " << player2.playerCard1 << " & " << player2.playerCard2 << " & " << player2.playerCard3 << " total " << sumOfCards2 << std::endl;

                            if (sumOfCards2 > 21)
                            {
                                std::cout << player2.name << " has bust " << std::endl;
                                // ADD DEALER SHOW CARDS AND GIVE MONEY
                                // playAgain(balance);
                                return;
                            }
                        }

                        if (player2.hitOrStand == 2)
                        {
                            dealerCard1 = rand() % 11 + 1;
                            dealerCard2 = rand() % 10 + 1;
                            sumOfDealerCards = dealerCard1 + dealerCard2;

                            if (sumOfDealerCards < 17)
                            {
                                while (sumOfDealerCards < 17)
                                {
                                    dealerCard3 = rand() % 10 + 1;
                                    sumOfDealerCards += dealerCard3;
                                }
                            }

                            std::cout << "Dealer is revealing his cards: " << std::endl;
                            std::cout << std::endl;
                            std::cout << "Dealer's cards are: " << dealerCard1 << " & " << dealerCard2 << " & " << dealerCard3 << " total " << sumOfDealerCards << std::endl;

                            if (sumOfDealerCards > 21)
                            {
                                std::cout << "Dealer has bust! " << std::endl;
                                player2.balance += bet2 + bet2;
                                std::cout << player2.name << " has won! " << std::endl;
                                std::cout << player1.name << " balance: " << player1.balance << std::endl;
                                std::cout << player2.name << " balance: " << player2.balance << std::endl;
                            }

                            if (sumOfCards2 > sumOfDealerCards)
                            {
                                player2.balance += bet2 + bet2;
                                std::cout << player2.name << " has won! " << std::endl;
                                std::cout << player1.name << " balance: " << player1.balance << std::endl;
                                std::cout << player2.name << " balance: " << player2.balance << std::endl;
                            }

                            if (sumOfCards2 < sumOfDealerCards)
                            {
                                std::cout << player2.name << " has lost! " << std::endl;
                                std::cout << player1.name << " balance: " << player1.balance << std::endl;
                                std::cout << player2.name << " balance:" << player2.balance << std::endl;
                            }

                            if (sumOfCards2 == sumOfDealerCards)
                            {
                                player1.balance += bet2;
                                std::cout << player2.name << " has drawn! " << std::endl;
                                std::cout << player1.name << " balance: " << player1.balance << std::endl;
                                std::cout << player2.name << " balance: " << player2.balance << std::endl;
                            }
                        }
                    } while (sumOfCards2 <= 21);
                    // playAgain(balance);
                    return;
                }
            }

            if (player1.hitOrStand == 2)
            {
                do
                {
                    std::cout << player2.name << " turn " << std::endl;
                    std::cout << "1. Hit " << std::endl;
                    std::cout << "2. Stand " << std::endl;
                    std::cin >> player2.hitOrStand;

                    if (player2.hitOrStand == 1)
                    {
                        player2.playerCard3 = rand() % 10 + 1;
                        sumOfCards2 += player2.playerCard3;
                        std::cout << player2.name << " cards are " << player2.playerCard1 << " & " << player2.playerCard2 << " & " << player2.playerCard3 << " total " << sumOfCards2 << std::endl;

                        if (sumOfCards2 > 21)
                        {
                            std::cout << player2.name << " has bust " << std::endl;
                            // ADD DEALER SHOW CARDS AND GIVE MONEY
                            // playAgain(balance);
                            return;
                        }
                    }

                    if (player2.hitOrStand == 2)
                    {
                        dealerCard1 = rand() % 11 + 1;
                        dealerCard2 = rand() % 10 + 1;
                        sumOfDealerCards = dealerCard1 + dealerCard2;

                        if (sumOfDealerCards < 17)
                        {
                            while (sumOfDealerCards < 17)
                            {
                                dealerCard3 = rand() % 10 + 1;
                                sumOfDealerCards += dealerCard3;
                            }
                        }
                        std::cout << "Dealer is revealing his cards: " << std::endl;
                        std::cout << std::endl;
                        std::cout << "Dealer's cards are: " << dealerCard1 << " & " << dealerCard2 << " & " << dealerCard3 << " total " << sumOfDealerCards << std::endl;

                        if (sumOfDealerCards > 21)
                        {
                            player1.balance += bet1 + bet1;
                            player2.balance += bet2 + bet2;
                            std::cout << player1.name << " has won! " << std::endl;
                            std::cout << player2.name << " has won! " << std::endl;

                            std::cout << player1.name << " balance: " << player1.balance << std::endl;
                            std::cout << player2.name << " balance: " << player2.balance << std::endl;
                            // playAgain(balance);
                        }

                        if (sumOfCards1 > sumOfDealerCards)
                        {
                            player1.balance += bet1 + bet1;
                            std::cout << player1.name << " has won! " << std::endl;
                            std::cout << player1.name << " balance: " << player1.balance << std::endl;
                        }

                        if (sumOfCards2 > sumOfDealerCards)
                        {
                            player2.balance += bet2 + bet2;
                            std::cout << player2.name << " has won! " << std::endl;
                            std::cout << player2.name << " balance: " << player2.balance << std::endl;
                        }

                        if (sumOfCards1 < sumOfDealerCards)
                        {
                            std::cout << player1.name << " has lost! " << std::endl;
                            std::cout << player1.name << " balance: " << player1.balance << std::endl;
                        }

                        if (sumOfCards2 < sumOfDealerCards)
                        {
                            std::cout << player2.name << " has lost! " << std::endl;
                            std::cout << player2.name << " balance:" << player2.balance << std::endl;
                        }

                        if (sumOfCards1 == sumOfDealerCards)
                        {
                            player1.balance += bet1;
                            std::cout << player1.name << " has drawn! " << std::endl;
                            std::cout << player1.name << " balance: " << player1.balance << std::endl;
                        }

                        if (sumOfCards2 == sumOfDealerCards)
                        {
                            player1.balance += bet2;
                            std::cout << player2.name << " has drawn! " << std::endl;
                            std::cout << player2.name << " balance: " << player2.balance << std::endl;
                        }
                    }
                } while (sumOfCards2 <= 21);
            }
        } while (sumOfCards1 <= 21 || sumOfDealerCards <= 21 || sumOfCards2 <= 21 || sumOfDealerCards <= 21);



    }
    if (input == 3)
    {
        Player player1;
        Player player2;
        Player player3;

        player1.balance;
        player2.balance;
        player3.balance;
    }
    if (input == 4)
    {
        Player player1;
        Player player2;
        Player player3;
        Player player4;

        player1.balance;
        player2.balance;
        player3.balance;
        player4.balance;
    }

}
// Single Player Module 

void menu()
{
    std::cout << "====================" << std::endl;
    std::cout << "Welcome to Blackjack" << std::endl;
    std::cout << "====================" << std::endl;
}

void game(int balance)
{
    std::cout << "You currently have a balance of " << balance << std::endl;
    int playerCard1, playerCard2, playerCard3, bet, dealerCard1, dealerCard2, dealerCard3{}, sumOfCards, sumOfDealerCards, hitOrStand;

    do
    {
        std::cout << "Enter your bet amount " << std::endl;
        std::cin >> bet;
        if (bet > balance)
        {
            std::cout << "You have bet too much, try again: " << std::endl;
        }
    } while (bet > balance);

    std::cout << "\n\n";

    balance -= bet;
    std::cout << "You have bet $" << bet << std::endl;
    std::cout << "Current balance is: " << "$" << balance << std::endl;
    std::cout << std::endl;
    std::cout << "Dealer is dealing cards... " << std::endl;
    srand(time(NULL));
    playerCard1 = rand() % 11 + 1;
    playerCard2 = rand() % 10 + 1;
    sumOfCards = playerCard1 + playerCard2;
    std::cout << "Your cards are " << playerCard1 << " & " << playerCard2 << " total: " << sumOfCards << std::endl;

    if (sumOfCards == 21)
    {
        dealerCard1 = rand() % 11 + 1;
        dealerCard2 = rand() % 10 + 1;
        sumOfDealerCards = dealerCard1 + dealerCard2;
        std::cout << "Dealer is revealing his cards: " << std::endl;
        std::cout << std::endl;
        std::cout << "Dealer's cards are: " << dealerCard1 << " & " << dealerCard2 << " total " << sumOfDealerCards << std::endl;

        if (sumOfDealerCards > sumOfCards)
        {
            balance += bet * 1.5;
            std::cout << "Blackjack, You have won! " << std::endl;
            std::cout << "Current balance is: " << "$" << balance << std::endl;
        }

        if (sumOfDealerCards < sumOfCards)
        {
            balance += bet * 1.5;
            std::cout << "Blackjack, You have won! " << std::endl;
            std::cout << "Current balance is: " << "$" << balance << std::endl;
        }

        if (sumOfDealerCards == sumOfCards)
        {
            balance += bet + bet;
            std::cout << "Draw! " << std::endl;
            std::cout << "Current balance is: " << "$" << balance << std::endl;
        }
    }

    do
    {
        std::cout << "**Enter corrosponding number for action**" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Hit " << std::endl;
        std::cout << "2. Stand " << std::endl;
        std::cin >> hitOrStand;

        if (hitOrStand == 1)
        {
            playerCard3 = rand() % 10 + 1;
            sumOfCards += playerCard3;
            std::cout << "Your cards are " << playerCard1 << " & " << playerCard2 << " & " << playerCard3 << " total:" << sumOfCards << std::endl;


            if (sumOfCards > 21)
            {
                std::cout << "You have bust!" << std::endl;
                playAgain(balance);
                return;

            }
        }

        if (hitOrStand == 2)
        {
            dealerCard1 = rand() % 11 + 1;
            dealerCard2 = rand() % 10 + 1;
            sumOfDealerCards = dealerCard1 + dealerCard2;
            if (sumOfDealerCards < 17)
            {
                while (sumOfDealerCards < 17)
                {
                    dealerCard3 = rand() % 10 + 1;
                    sumOfDealerCards += dealerCard3;
                }
            }
            std::cout << "Dealer is revealing his cards: " << std::endl;
            std::cout << std::endl;
            std::cout << "Dealer's cards are: " << dealerCard1 << " & " << dealerCard2 << " & " << dealerCard3 << " total " << sumOfDealerCards << std::endl;

            if (sumOfDealerCards > 21)
            {
                balance += bet + bet;
                std::cout << "You have won! " << std::endl;
                std::cout << "Current balance is: " << "$" << balance << std::endl;
                playAgain(balance);
            }

            if (sumOfCards > sumOfDealerCards)
            {
                balance += bet + bet;
                std::cout << "You have won! " << std::endl;
                std::cout << "Current balance is: " << "$" << balance << std::endl;
                playAgain(balance);
                return;
            }

            if (sumOfCards < sumOfDealerCards)
            {
                std::cout << "You have lost " << std::endl;
                playAgain(balance);
                return;
            }

            if (sumOfCards == sumOfDealerCards)
            {
                balance += bet;
                std::cout << "Draw! " << std::endl;
                std::cout << "Current balance is: " << "$" << balance << std::endl;
                playAgain(balance);
                return;
            }
        }
    } while (sumOfCards <= 21 || sumOfDealerCards <= 21);
}

bool playAgain(int balance)
{
    int play;
    std::cout << "1. Play Again? " << std::endl;
    std::cout << "2. Back Out " << std::endl;
    std::cin >> play;

    if (play == 1)
    {
        if (balance <= 0)
        {
            std::cout << "You have no more money to spend " << std::endl;
            return true;
        }
        game(balance);
        return false;
    }
    if (play == 2)
    {
        std::cout << "Thanks for playing! " << std::endl;
        return true;
    }

    return true;
}


