#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h> // for Sleep and colors
#include <conio.h>
#include <time.h>
#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_ENTER 13

void splash(char board[3][3]) // to prin tth eboard in an aesthetic way
{
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to return a random number from 1 to 9
int random_1_to_9() {
    return (rand() % 9) + 1;
}

void blue() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}

void white() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_INTENSITY
        | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void red() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void green() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void type_effect(const char *text, int delay_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        Sleep(delay_ms); // delay per character
    }
}
bool empty (char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != ' ')
                return false; 
    return true; 
}

void makesempty (char  board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 3; j++)
       {
          board[i][j] = ' ' ;
       }
    }
    
}

bool checkexistintegerinside1Darray(int size ,int array[size],int uponcheck)
{
for (int i = 0; i < size; i++)
{
if (array[i]==uponcheck)
{
return true ;
}
}
return false ;
}


bool p1win (char board[3][3]) //checks for three consecutive Xs
{
    // checking rows
for (int i = 0; i < 3; i++)
{
if((( board[i][0]== 'X')||(board[i][0]== 'x'))&&(( board[i][1]== 'X')||(board[i][1]== 'x'))&&(( board[i][2]== 'X')||(board[i][2]=='x')) ) return true ;
}
// checking columns
for (int i = 0; i < 3; i++)
{
if((( board[0][i]== 'X')||(board[0][i]== 'x'))&&(( board[1][i]== 'X')||(board[1][i]== 'x'))&&(( board[2][i]== 'X')||(board[2][i]== 'x')) ) return true ;
}
// checking diagonals
//left top to right bottom diagonal
if((( board[0][0]== 'X')||(board[0][0]== 'x'))&&(( board[1][1]== 'X')||(board[1][1]== 'x'))&&(( board[2][2]== 'X')||(board[2][2]== 'x'))) return true ;
// right top to left bottom diagonal
if((( board[2][0]== 'X')||(board[2][0]== 'x'))&&(( board[1][1]== 'X')||(board[1][1]== 'x'))&&(( board[0][2]== 'X')||(board[0][2]== 'x'))) return true ;
return false ; //incase of lossssssssssssssssssssssssssssssssssssssssssssssssss
}
bool p2win (char board[3][3]) //checks for three consecutive Os
{
    // checking rows
for (int i = 0; i < 3; i++)
{
if((( board[i][0]== 'O')||(board[i][0]== 'o'))&&(( board[i][1]== 'O')||(board[i][1]== 'o'))&&(( board[i][2]== 'O')||(board[i][2]=='o')) ) return true ;
}
// checking columns
for (int i = 0; i < 3; i++)
{
if((( board[0][i]== 'O')||(board[0][i]== 'o'))&&(( board[1][i]== 'O')||(board[1][i]== 'o'))&&(( board[2][i]== 'O')||(board[2][i]== 'o')) ) return true ;
}
// checking diagonals
//left top to right bottom diagonal
if((( board[0][0]== 'O')||(board[0][0]== 'o'))&&(( board[1][1]== 'O')||(board[1][1]== 'o'))&&(( board[2][2]== 'O')||(board[2][2]== 'o'))) return true ;
// right top to left bottom diagonal
if((( board[2][0]== 'O')||(board[2][0]== 'o'))&&(( board[1][1]== 'O')||(board[1][1]== 'o'))&&(( board[0][2]== 'O')||(board[0][2]== 'o'))) return true ;
return false ; //incase of lossssssssssssssssssssssssssssssssssssssssssssssssss
}
bool draw (char board[3][3], int count )
{
  // draw happens when the moves count is equal to 9 and both the win functions are false 
  if((p1win(board) == false && count == 9)||(p2win(board) == false && count == 9) ) return true ;
  return false ;
}

int main()
{
    
srand(time(NULL));     
char board[3][3] ={' '} ;    
int choice ; 
    do{
// The menu of the game+ intia + declaraiton of variables
int c1 = 0 ;
int c2 = 0 ;
int hamood = 0 ;
int moves_count = 0 ;
int  p1choices[9]= {0} ;
int  p2choices[9]= {0} ;
board[0][0] ='1' ;
board[0][1] ='2' ;
board[0][2] ='3' ;
board[1][0] ='4' ;
board[1][1] = '5';
board[1][2] = '6';
board[2][0] = '7';
board[2][1] = '8';
board[2][2] = '9' ;

    white() ;
    type_effect("  __  __ _____ _   _ _   _ \n",20);
    type_effect(" |  \\/  | ____| \\ | | | | |\n",20);
    type_effect(" | |\\/| |  _| |  \\| | | | |\n",20);
    type_effect(" | |  | | |___| |\\  | |_| |\n",20);
    type_effect(" |_|  |_|_____|_| \\_|\\____/ \n",20);

    type_effect("\nWELCOME TO TIC TAC TOE !!\n",20);
    blue(); 
    type_effect("1.Player Vs Player\n",20);
    type_effect("2.Player Vs Computer\n",20);
    type_effect("3.View Rules\n",20);
    type_effect("4.Exit\n",20);

    white();
    type_effect("\n\nEnter your choice :\n",30);

scanf("%d",&choice ) ;
switch (choice) {
    case 1:

// start of the game
int hamood = 0;
green();
type_effect("Starting \"Player1 Vs a Player2\" \n",5);
red();  
type_effect("Reminder : Player1 is X & Player2 is O \n",5); 
do
{  
// section1 : player1

    green();
    type_effect("Player1's Turn . Choose a box's number : \n",5); 
splash (board) ;
scanf("%d",&c1 );


while((checkexistintegerinside1Darray(9 ,p1choices, c1)==true)||(c1>9)||(c1<1)||(checkexistintegerinside1Darray(9 ,p2choices, c1)==true))
{
    type_effect("Invalid input , choose another number\n",5); 
    scanf("%d",&c1 );

}

p1choices[hamood]  =c1 ;
if (c1 == 1)
{
board[0][0]= 'X' ;
}
else if (c1 == 2) {
board[0][1]= 'X' ;
}
else if (c1 == 3) {
board[0][2]= 'X' ;
}
else if (c1 == 4) {
board[1][0]= 'X' ;
}
else if (c1 == 5) {
board[1][1]= 'X' ;
}
else if (c1 == 6) {
board[1][2]= 'X' ;
}
else if (c1 == 7) {
board[2][0]= 'X' ;
}
else if (c1 == 8) {
board[2][1]= 'X' ;
}
else if (c1 == 9) {
board[2][2]= 'X' ;
}
type_effect("---------------------------------------------\n\n",5); 
splash(board) ;
if (p1win(board)==true)
{
  green() ;
  type_effect("Player1 has won!!! \n",10);   
  break ;
}
// section2: player2

    red();
    type_effect("Player2's Turn . Choose a box's number : \n",5); 
splash(board) ;
scanf("%d",&c2 );

while((checkexistintegerinside1Darray(9 ,p2choices, c2)==true)||(c2>9)||(c2<1)||(checkexistintegerinside1Darray(9 ,p1choices, c2)==true))
{
    type_effect("Invalid input , choose another number\n",5); 
    scanf("%d",&c2 );

}

p2choices[hamood]  = c2 ;
if (c2 == 1)
{
board[0][0]= 'O' ;
}
else if (c2 == 2) {
board[0][1]= 'O' ;
}
else if (c2 == 3) {
board[0][2]= 'O' ;
}
else if (c2 == 4) {
board[1][0]= 'O' ;
}
else if (c2 == 5) {
board[1][1]= 'O' ;
}
else if (c2 == 6) {
board[1][2]= 'O' ;
}
else if (c2 == 7) {
board[2][0]= 'O' ;
}
else if (c2 == 8) {
board[2][1]= 'O' ;
}
else if (c2 == 9) {
board[2][2]= 'O' ;
}
type_effect("---------------------------------------------\n\n",5); 
splash(board) ;

hamood++ ;
moves_count++ ;
} while (p1win(board)==false && p2win(board)==false && draw(board,moves_count)==false);


if (p2win(board)==true) {
  red() ;
  type_effect("Player2 has won!!! \n",10);  
}
else if (draw(board,moves_count)==true) {
white();
  type_effect("This is a tie ! \n",10);  
}

    break;

    case 2:
    green();
    type_effect("Starting \"Player Vs Computer\" \n",5);
    white();   
    do
    {
// section1 : player1

    green();
    type_effect("Player1's Turn . Choose a box's number : \n",5); 
splash (board) ;
scanf("%d",&c1 );


while((checkexistintegerinside1Darray(9 ,p1choices, c1)==true)||(c1>9)||(c1<1)||(checkexistintegerinside1Darray(9 ,p2choices, c1)==true))
{
    type_effect("Invalid input , choose another number\n",5); 
    scanf("%d",&c1 );

}

p1choices[hamood]  =c1 ;
if (c1 == 1)
{
board[0][0]= 'X' ;
}
else if (c1 == 2) {
board[0][1]= 'X' ;
}
else if (c1 == 3) {
board[0][2]= 'X' ;
}
else if (c1 == 4) {
board[1][0]= 'X' ;
}
else if (c1 == 5) {
board[1][1]= 'X' ;
}
else if (c1 == 6) {
board[1][2]= 'X' ;
}
else if (c1 == 7) {
board[2][0]= 'X' ;
}
else if (c1 == 8) {
board[2][1]= 'X' ;
}
else if (c1 == 9) {
board[2][2]= 'X' ;
}
type_effect("---------------------------------------------\n\n",5); 
splash(board) ;
if (p1win(board)==true)
{
  green() ;
  type_effect("Player1 has won!!! \n",10);   
  break ;
}
// section2: computer

    red();
// computer chhpsing a random number between 1 to 9


c2 = random_1_to_9() ;

while((checkexistintegerinside1Darray(9 ,p2choices, c2)==true)||(c2>9)||(c2<1)||(checkexistintegerinside1Darray(9 ,p1choices, c2)==true))
{
    
c2 = random_1_to_9() ;
}

p2choices[hamood]  = c2 ;
if (c2 == 1)
{
board[0][0]= 'O' ;
}
else if (c2 == 2) {
board[0][1]= 'O' ;
}
else if (c2 == 3) {
board[0][2]= 'O' ;
}
else if (c2 == 4) {
board[1][0]= 'O' ;
}
else if (c2 == 5) {
board[1][1]= 'O' ;
}
else if (c2 == 6) {
board[1][2]= 'O' ;
}
else if (c2 == 7) {
board[2][0]= 'O' ;
}
else if (c2 == 8) {
board[2][1]= 'O' ;
}
else if (c2 == 9) {
board[2][2]= 'O' ;
}
type_effect("---------------------------------------------\n\n",5); 
splash(board) ;

hamood++ ;
moves_count++ ;
} while (p1win(board)==false && p2win(board)==false && draw(board,moves_count)==false);
if (p2win(board)==true) {
red() ;
type_effect("Computer has won!!! \n",10);  
}
else if (draw(board,moves_count)==true) {
white();
  type_effect("This is a tie ! \n",10);  
}
   
    break;

    case 3:
    green();
    type_effect("\n--- Tic-Tac-Toe Rules ---\n",15);
    type_effect("1. The game is played on a 3x3 grid.\n",15);
    type_effect("2. Player 1 is X, Player 2 is O.\n",15);
    type_effect("3. Players take turns placing their mark.\n",15);
    type_effect("4. First to get 3 in a row (horizontal, vertical, or diagonal) wins.\n",15);
    type_effect("5. If the board is full and no one has won, it's a draw.\n\n",15);
    white();  
    break;

    case 4:
    red() ;
    type_effect("Exiting the game. Goodbye!\n",20);
    white() ;
    break;    
}
} while (choice != 4);

    return 0;
}