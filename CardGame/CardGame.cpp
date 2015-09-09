// CardGame2.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

bool gameRunning;
bool playerTurn;
int player1Hand[15];
int player2Hand[15];
int player1ChoiceCard;
int player2ChoiceCard;
int player1Score;
int player2Score;
int screenClear;
int x;
int cardA;
int cardB;

int EndGameCounterDEBUG;

int CompareCard()
{
    //return 0 if draw, 1 if P1 win , 2 if P2 win
    
    if ((cardA != 1) && (cardB != 13))
    {
        cout << "Player A wins!" << endl;
        ++player1Score;
        return 1;
    }
    else if ((cardA != 13) && (cardB != 1))
    {
        cout << "Player B wins!" << endl;
        ++player2Score;
        return 2;
    }
    else if (cardA == cardB)
    {
        cout << "Both players draw!" << endl;
        return 0;
    }
    else if ((cardA == 0) && (cardB != 0))
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
    else if ((cardB == 0) && (cardA != 0))
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
    else if ((cardA == 0) && (cardB == 0))
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
    else if (cardA > cardB)
    {
        cout << "Player A wins!" << endl;
        ++player1Score;
        return 1;
    }
    else if (cardA < cardB)
    {
        cout << "Player B wins!" << endl;
        ++player2Score;
        return 2;
    }
    return 0;
}

int Game()
{
    //cout << "hello world \n";
    
    
    
    cout << "Press 'Enter' when Player 1 is ready... \n";
    
    if (cin.get() == '\n')
    {
        //int tempCount;
        while (screenClear <= 30)
        {
            cout << "\n";
            screenClear++;
        }
        screenClear = 0;
    }
    
    
    
    EndGameCounterDEBUG++;
    
    if (EndGameCounterDEBUG >= 15)
    {
        gameRunning = 0;
    }
    
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
        
        while (gameRunning == 1)
        {
            Game();
        }
        
        cout << "end \n";
        
        cin.get();
        return 0;
        
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
