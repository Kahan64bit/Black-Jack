#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


void game(int);
void menu();
bool playAgain(int);


int main()
{
    int balance = 100;
    menu();
    game(balance);
}

void menu()
{
    std::cout << "====================" << std::endl;
    std::cout << "Welcome to Blackjack" << std::endl;
    std::cout << "====================" << std::endl;

    std::cout << "You currently have a balance of $100 " << std::endl;
}

void game(int balance)
{

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
            balance += bet;
            std::cout << "Blackjack, You have won! " << std::endl;
            std::cout << "Current balance is: " << "$" << balance << std::endl;
        }

        if (sumOfDealerCards < sumOfCards)
        {
            balance += bet;
            std::cout << "Blackjack, You have won! " << std::endl;
            std::cout << "Current balance is: " << "$" << balance << std::endl;
        }

        if (sumOfDealerCards == sumOfCards)
        {
            balance += bet;
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
                balance += bet * 5;
                std::cout << "You have won! " << std::endl;
                std::cout << "Current balance is: " << "$" << balance << std::endl;
                playAgain(balance);
            }

            if (sumOfCards > sumOfDealerCards)
            {
                balance += bet * 5;
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


