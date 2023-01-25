// TicTacToe.cpp
// Anna Tran, CISP 360
// 4/26/2020

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Specification B5 - Array Data Type
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
     
    
void board(),
     menu(),
     reset(char square[], int Cmoves[], int Pmoves[]);
    

int wincheck(),
    computermove (char square[], int Cmoves[]),
    playermove (char square[], int Pmoves[]),
    Cmoves[5],
    Pmoves[5];

// Specification C5 - No Globals

int main() {
  int player,
      i = -1,
      choice,
      mchoice,
      cwin = 0,
      pwin = 0;
  
  bool newgame = true;
  

  char mark,
       play = 'y';

  menu();
  cin >> mchoice;
  
  //Specification B2 - Valid Menu Choices
  while (!(mchoice <= 3 && mchoice >= 1))
  {
    cout << "\nInvalid choice. Try again: \n";
    cin >> mchoice;
  }

  switch (mchoice)
  {
    case 1:
      cout << "\nPick an avaliable number to choose that square. Get three in a row to win.\n";
      
    break;

    case 2:
    
    // Specification A1 - Main Game Loop
    do
    {
        if (newgame == true)
        {
        reset(square, Cmoves, Pmoves);
        cout << Cmoves[1];
        }
        cout << square[1];
        board();
        // Specification C1 - Random Start
        srand(time(0));
        player = (rand() % 2);
    
      while (i == -1)
      {
          
          if (player == 0)
          {player = 0;}
          else{player = 1;}

          if (player == 0) {mark = 'X';}
          else {mark = 'O';}

          if (player == 0)
          {
          
          choice = playermove(square, Pmoves);
          cout << choice;
          }

          else 
          {
            choice = computermove(square, Cmoves);
          }
          

          if (choice == 1 && square[1] == '1')
              square[1] = mark;

          else if (choice == 2 && square[2] == '2')
              square[2] = mark;

          else if (choice == 3 && square[3] == '3')
              square[3] = mark;

          else if (choice == 4 && square[4] == '4')
              square[4] = mark;

          else if (choice == 5 && square[5] == '5')
              square[5] = mark;

          else if (choice == 6 && square[6] == '6')
              square[6] = mark;

          else if (choice == 7 && square[7] == '7')
              square[7] = mark;

          else if (choice == 8 && square[8] == '8')
              square[8] = mark;

          else if (choice == 9 && square[9] == '9')
              square[9] = mark;
          
          player = 1 - player;
          board();
          i=wincheck();
          
          
      }
      
      
      if(i==1)
          {
          if (player == 0)
          {
            cout<<"Player 1 wins ";
            
          }
          
          else 
          {
            cout << "Player 0 wins";
          }
          }
      else
          cout<<"\aGame draw";
      
      // Specification A3 - Keep Score
      if (player == 0){pwin++;}
      else {cwin++;}
      
      cout << "\nPlay by Play: " << "\n===========";
      cout << "\nPlayer 0: ";
            for (int i = 0; i < 5; i++)
              if (Pmoves[i] != 0)
              {
                cout << Pmoves[i];
              }

      cout << "\nPlayer 1: ";
            for (int i = 0; i < 5; i++)
              if (Cmoves[i] != 0)
              {
                cout << Cmoves[i];
              }
      
      // Specification A2 - Simple Prompt
      cout << "\n\nPlay Again? (y/n)\n";
      cin >> play;

    

      if (play == 'y' || play == 'Y')
      {
        i = -1;
        newgame = true;
      }

      else 
      { 
        cout << "\nScores: " << "\n=======\n" << "Player 0: " << pwin << "\nPlayer 1: " << cwin << endl;
        cout << "\nProgram Closed.\n";
      }

      } while (play != 'n' && play != 'N');
      
    break;

    case 3:
    cout << "\nProgram Closed.\n";
    break;
    return 0;
  
  }
  }
  


void board()
{
  // Specification B3 - Pretty Display
  cout << string(5, '\n');
  cout << "\n\n\tLet's Play: Tic Tac Toe\n\n";

  cout << "You (X)  -  AI (O)\n\n" << endl;
  cout << "\t     |     |     " << endl;
  cout << "\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

  cout << "\t_____|_____|_____" << endl;
  cout << "\t     |     |     " << endl;

  cout << "\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

  cout << "\t_____|_____|_____" << endl;
  cout << "\t     |     |     " << endl;

  cout << "\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

  cout << "\t     |     |     " << endl << endl;

  // Specification C2 - Simple Display

  //cout << string(5, '\n');
  //cout << "\n\n\tLet's Play: Tic Tac Toe\n\n";

  //cout << "You (X)  -  AI (O)\n\n" << endl;
  //cout << "\t     |     |     " << endl;
  //cout << "\t  " << " " << "  |  " << " " << "  |  " << " " << endl;

  //cout << "\t_____|_____|_____" << endl;
  //cout << "\t     |     |     " << endl;

  //cout << "\t  " << " " << "  |  " << " " << "  |  " << " " << endl;

  //cout << "\t_____|_____|_____" << endl;
  //cout << "\t     |     |     " << endl;

  //cout << "\t  " << " " << "  |  " << " " << "  |  " << " " << endl;

  //cout << "\t     |     |     " << endl << endl;
}

// Specification C4 - Decide Winner
int wincheck()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

int computermove(char square[], int Cmoves[]) 
{
  // Specification C3 - AI
  int choice;
  
  char check = '0';

  cout << "\nComputer's turn.\n";

    while (!(check == '1'))
    {
      srand(time(0));
      choice = (rand() % 9) + 1;
      
      if (square[1] == '1' && choice == 1) {choice = 1, check = '1';}
      else if (square[2] == '2' && choice == 2) {choice = 2, check = '1';} 
      else if (square[3] == '3' && choice == 3) {choice = 3, check = '1';} 
      else if (square[4] == '4' && choice == 4) {choice = 4, check = '1';} 
      else if (square[5] == '5' && choice == 5) {choice = 5, check = '1';} 
      else if (square[6] == '6' && choice == 6) {choice = 6, check = '1';} 
      else if (square[7] == '7' && choice == 7) {choice = 7, check = '1';}
      else if (square[8] == '8' && choice == 8) {choice = 8, check = '1';} 
      else if (square[9] == '9' && choice == 9) {choice = 9, check = '1';}
      else {check = '0';}
    }

    cout << choice;
  
  // Specification A4 - Play by Play
  if (Cmoves [0] == 0) {Cmoves [0] = choice;}
  else if (Cmoves [1] == 0) {Cmoves [1] = choice;}
  else if (Cmoves [2] == 0) {Cmoves [2] = choice;}
  else if (Cmoves [3] == 0) {Cmoves [3] = choice;}
  else if (Cmoves [4] == 0) {Cmoves [4] = choice;}
  
  return choice;
}

// Specification A5 - Using Functions
int playermove (char square[], int Pmoves[])
{
  int choice,
      check = '0';
  
  cout << "\nPlayer 0, enter a number: ";
  
  
  // Specification B4 – Valid Move
  while (!(check == '1'))
    {
      cin >> choice;

      if (square[1] == '1' && choice == 1) {choice = 1, check = '1';}
      else if (square[2] == '2' && choice == 2) {choice = 2, check = '1';} 
      else if (square[3] == '3' && choice == 3) {choice = 3, check = '1';} 
      else if (square[4] == '4' && choice == 4) {choice = 4, check = '1';} 
      else if (square[5] == '5' && choice == 5) {choice = 5, check = '1';} 
      else if (square[6] == '6' && choice == 6) {choice = 6, check = '1';} 
      else if (square[7] == '7' && choice == 7) {choice = 7, check = '1';}
      else if (square[8] == '8' && choice == 8) {choice = 8, check = '1';} 
      else if (square[9] == '9' && choice == 9) {choice = 9, check = '1';}
      else 
        {
          check = '0';
          cout << "Invalid Input, try again: ";
        }
    }
  if (Pmoves [0] == 0) {Pmoves [0] = choice;}
  else if (Pmoves [1] == 0) {Pmoves [1] = choice;}
  else if (Pmoves [2] == 0) {Pmoves [2] = choice;}
  else if (Pmoves [3] == 0) {Pmoves [3] = choice;}
  else if (Pmoves [4] == 0) {Pmoves [4] = choice;}
  
  return choice;
}

void menu ()
{
  // Specification B1 - Start Menu
  cout << "\nMenu: \n" << "=======" << "\n1. Explain Game\n" << "2. Play\n" << "3. Quit\n" << endl;
}

void reset (char square[], int Cmoves[], int Pmoves[])
{
  square[1] = '1';
  square[2] = '2';
  square[3] = '3';
  square[4] = '4';
  square[5] = '5';
  square[6] = '6';
  square[7] = '7';
  square[8] = '8';
  square[9] = '9';

  Cmoves[0] = 0;
  Cmoves[1] = 0;
  Cmoves[2] = 0;
  Cmoves[3] = 0;
  Cmoves[4] = 0;

  Pmoves[0] = 0;
  Pmoves[1] = 0;
  Pmoves[2] = 0;
  Pmoves[3] = 0;
  Pmoves[4] = 0;

}
