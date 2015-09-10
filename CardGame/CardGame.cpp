// CardGame2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

bool gameRunning;
bool playerTurn;
int player1ChoiceCard;
int player2ChoiceCard;
vector<int> player1Hand;
vector<int> player2Hand;
int player1Score;
int player2Score;
int screenClear;
int x;

int EndGameCounterDEBUG;

int CompareCard()
{
    //return 0 if draw, 1 if P1 win , 2 if P2 win
    
    srand(time(0));
    
    if ((player1ChoiceCard == 1) && (player2ChoiceCard == 13))
    {
        cout << "Player A wins!" << endl;
        ++player1Score;
        return 1;
    }
    else if ((player1ChoiceCard == 13) && (player2ChoiceCard == 1))
    {
        cout << "Player B wins!" << endl;
        ++player2Score;
        return 2;
    }
    else if ((player1ChoiceCard == 0) && (player2ChoiceCard != 0))
    {
        if (rand() % 100 < 50)
        {
            cout << "Player A wins!" << endl;
            ++player1Score;
            return 1;
        }
        else if (rand() % 100 > 50)
        {
            cout << "Player B wins!" << endl;
            ++player2Score;
            return 2;
        }
    }
    else if ((player2ChoiceCard == 0) && (player1ChoiceCard != 0))
    {
        if (rand() % 100 < 50)
        {
            cout << "Player B wins!" << endl;
            ++player2Score;
            return 2;
        }
        else if (rand() % 100 > 50)
        {
            cout << "Player A wins!" << endl;
            ++player1Score;
            return 1;
        }
    }
    else if ((player1ChoiceCard == 0) && (player2ChoiceCard == 0))
    {
        if (rand() % 100 < 50)
        {
            cout << "Both players draw by chance!" << endl;
            return 0;
        }
        else if (rand() % 100 > 25 )
        {
            cout << "Player A wins by chance!" << endl;
            ++player1Score;
            return 1;
        }
        else if (rand() % 100 > 25 )
        {
            cout << "Player B wins by chance!" << endl;
            ++player2Score;
            return 2;
        }
    }
    else if (player1ChoiceCard == player2ChoiceCard)
    {
        cout << "Both players draw!" << endl;
        return 0;
    }
    else if (player1ChoiceCard > player2ChoiceCard)
    {
        cout << "Player A wins!" << endl;
        ++player1Score;
        return 1;
    }
    else if (player1ChoiceCard < player2ChoiceCard)
    {
        cout << "Player B wins!" << endl;
        ++player2Score;
        return 2;
    }
    return 0;
}

void ClearScreen()
{
    while (screenClear <= 30)
    {
        cout << "\n";
        screenClear++;
    }
    screenClear = 0;
}

int Game()
{
    //cout << "hello world \n";
    //cout << "Hand A Size " << player1Hand.size() << "hand B Size " << player2Hand.size() << "\n";
    
    cin.get();
    
    cout << "Press 'Enter' when Player A is ready... \n";
    
    if (cin.get() == '\n')
    {
        ClearScreen();
    }
    
    cout << "A - Available cards: ";
    for (auto i = player1Hand.begin(); i != player1Hand.end(); ++i)
    {
        cout << *i << ' ';
    }
    cout << "\n";
    cout << "a> ";
    
    cin >> player1ChoiceCard;
    while (cin.fail())
    {
        if (cin.fail())
        {
            cout << "Please input valid number. \n";
            cin.clear();
            cin.ignore();
        }
        cin >> player1ChoiceCard;
    }
    
    ClearScreen();
    cin.clear();
    cin.ignore();
    
    cout << "Press 'Enter' when Player B is ready... \n";
    
    if (cin.get() == '\n')
    {
        ClearScreen();
    }
    
    cout << "B - Available cards: ";
    for (auto i = player2Hand.begin(); i != player2Hand.end(); ++i)
    {
        cout << *i << ' ';
    }
    cout << "\n";
    cout << "b> ";
    
    cin >> player2ChoiceCard;
    while (cin.fail())
    {
        if (cin.fail())
        {
            cout << "Please input valid number. \n";
            cin.clear();
            cin.ignore();
        }
        cin >> player2ChoiceCard;
    }
    
    ClearScreen();
    
    cout << "Joust: " << player1ChoiceCard << " vs " << player2ChoiceCard <<endl;
    CompareCard();
    //if ()
    
    //EndGameCounterDEBUG++;
    
    //if (EndGameCounterDEBUG >= 15)
    //{
    //gameRunning = 0;
    //}
    
    cin.get();
    
    return 0;
}

int main()
{
    cout << "Welcome to the Card Game by Umbrella Corp!" <<endl;
    cout << "1. How to Play" <<endl;
    cout << "2. Start Game" <<endl;
    cout << "3. Exit" <<endl;
    
    do {cin>>x;}
    while (x == 3);
    
    if (x == 1)
    {
        cout << "How to Play" <<endl;
        cout << "1.  Each player is allocated 15 cards. Two of the cards are jokers. (the 0 cards) The rest are labeled 1 to 13." <<endl;
        cout << "2.  Each player uses a card to joust. Except for the jokers, a higher card beats a lower card. But 1 beats 13. The jokers randomly wins or loses against the other card. If both players chose jokers, then there's 50% chance of a draw, 25% chance of the the first player winning, and 25% chance of the other player winning." <<endl;
        cout << "3.  A player gets a point only when he wins the joust. For a draw, no points will be given to any player." <<endl;
        cout << "4.  The jousts will keep on going until all cards are used up. So there will be 15 rounds/jousts in total." << endl;
        
        do
        {
            cin >> x;
        }
        while (x == 3);
    }
    
    if (x == 2)
    {
        gameRunning = 1;
        player1Hand = {0,0,1,2,3,4,5,6,7,8,9,10,11,12,13};
        player2Hand = {0,0,1,2,3,4,5,6,7,8,9,10,11,12,13};
        player1Score = 0;
        player2Score = 0;
        
        while (gameRunning == 1)
        {
            Game();
            
            if ((player1Hand.empty()) && (player2Hand.empty()))
            {
                gameRunning = 0;
            }
        }
        
        cout << "Player A: " << player1Score << endl;
        cout << "Player B: " << player2Score << endl;
        cout << "Draws: " << (15 - (player1Score + player2Score)) << endl;
        if (player1Score > player2Score)
        {
            cout << "**Player A wins!**" << endl;
        }
        else if (player2Score > player1Score)
        {
            cout << "**Player B wins!**" << endl;
        }
        else
        {
            cout << "Player A and B are tied!!" << endl;
        }
        
        cout << "end \n";
        
        cin.get();
        //return 0;
    }
    
    if (x == 3)
    {
        do
        {
            cin >> x;
        }
        while (x == 3);
        
        system("pause");
    }
    
    
    
    return 0;
    
}

