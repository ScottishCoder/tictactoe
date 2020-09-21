#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

int main(){

    // Board creation as 1 dimensional array

    char board[9];

    // contains all board positions
    board[0] = '0';
    board[1] = '1';
    board[2] = '2';
    board[3] = '3';
    board[4] = '4';
    board[5] = '5';
    board[6] = '6';
    board[7] = '7';
    board[8] = '8';

    // cross checker function checks to see if player 1 or 2 has full set
    int crossChecker(){

    // Horizontal Check

        if(board[0] == 'x' && board[1] == 'x' && board[2] == 'x'){
                // sets terminal to green
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 1;
            // breaks the loop to return result. 1 = player one, 2 = player two

        }
        else if(board[0] == 'o' && board[1] == 'o' && board[2] == 'o'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 2;

        }
        if(board[3] == 'x' && board[4] == 'x' && board[5] == 'x'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 1;

        }
        else if(board[3] == 'o' && board[4] == 'o' && board[5] == 'o'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 2;

        }
        if(board[6] == 'x' && board[7] == 'x' && board[8] == 'x'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 1;

        }
        else if(board[6] == 'o' && board[7] == 'o' && board[8] == 'o'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 2;

        }

        // vertical wins
        if(board[0] == 'x' && board[3] == 'x' && board[6] == 'x'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 1;

        }
        else if(board[0] == 'o' && board[3] == 'o' && board[6] == 'o'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 2;

        }

        if(board[1] == 'x' && board[4] == 'x' && board[7] == 'x'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 1;

        }
        else if(board[1] == 'o' && board[4] == 'o' && board[7] == 'o'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 2;

        }

         if(board[2] == 'x' && board[5] == 'x' && board[8] == 'x'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 1;

        }
        else if(board[2] == 'o' && board[5] == 'o' && board[8] == 'o'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 2;

        }

        // diagonal wins

        if(board[0] == 'x' && board[4] == 'x' && board[8] == 'x'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 1;

        }
        else if(board[0] == 'o' && board[4] == 'o' && board[8] == 'o'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 2;

        }

         if(board[2] == 'x' && board[4] == 'x' && board[6] == 'x'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 1;

        }
        else if(board[2] == 'o' && board[4] == 'o' && board[6] == 'o'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            return 2;

        }




    }

    // gets players position choice and acts as validation to check if position has already been taken
    int playerInsert(){
        int playerChoice = 0;
        scanf("%d", &playerChoice);
        if(board[playerChoice] == 'x' || board[playerChoice] == 'o'){
            // 99 is just a random number to send back which alerts the game that a position is already taken
            return 99;
        }

        return playerChoice;
    }


    // Draws the board onto the terminal
    void drawBoard(){
        // For loop is used to draw the board.
        for(int j =0; j<=8; j++){
            printf("--------[%c]--------", board[j]);
            // Using J as counter, it acts as the partition to break the board every 3 columns
             switch(j){
             case 2:
                printf("\n\n\n");
                break;
             case 5:
                printf("\n\n\n");
                break;
             case 8:
                printf("\n\n\n");
                break;
                }
        }

    }

    printf("Welcome to Tic-Tac-Toe. \n");
    printf("Player one starts first. \n");
    printf("Player 1 = x \n");
    printf("player 2 = o \n");

    // player turn check acts as counter. So first turn = 1 is player 1, then loop ++ adds to counter, 2 = player twos turn
    int player_turn_check = 0;

    // Main game loop.
    while(true){
        // Draws board to terminal
        drawBoard();
        // get players choice
        int choice = playerInsert();
        if(choice == 99){
            printf("\033[31mAlready chosen, please choose again\n\033[0m");
            continue;
        }else{
            // using player turn check counter, we can allow turns by using a switch statement.
            switch(player_turn_check){
            case 0:
                board[choice] = 'x';
                break;
            case 1:
                board[choice] = 'o';
                break;
            case 2:
                board[choice] = 'x';
                break;
            case 3:
                board[choice] = 'o';
                break;
            case 4:
                board[choice] = 'x';
                break;
            case 5:
                board[choice] = 'o';
                break;
            case 6:
                board[choice] = 'x';
                break;
            case 7:
                board[choice] = 'o';
                break;
            case 8:
                board[choice] = 'x';
                break;
            case 9:
                board[choice] = 'o';
                break;
            default:
                printf("finished");

            }
        }

        player_turn_check++;
        int winner = crossChecker(); // returns either 1 or 2.
        if(winner == 1){
            printf("PLAYER 1 WINS THE GAME!\n");
            getchar();
            // recall the board to show results without having to run through the loop once more
            drawBoard();
            printf("Thanks for playing. Press ENTER to close the game.");
            getchar();
            return false;
        }
        else if(winner == 2){
            printf("PLAYER 2 WINS THE GAME!\n");
            getchar();
            drawBoard();
            printf("Thanks for playing. Press ENTER to close the game.");
            getchar();
            return false;
        }
        // clear the system so it does not leave an imprint of the last board draw
        system("@cls||clear");

    }
// exit program
printf("Thanks for playing. Press ENTER to close the game.");
getchar();
return 0;
}
