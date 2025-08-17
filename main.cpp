#include <iostream>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

// Function to print the Tic Tac Toe board
void print_board(string board[]){
    for(int i = 0; i < 3; i++){
        cout<<board[i][0]<<" | "<<board[i][1]<<" | "<<board[i][2]<<endl;
        if(i < 2){
            cout<<"--|---|--"<<endl;
        }
    }
    cout<<endl;
}

// Function to check if a player has won
bool check_win(string board[], char player){
    // Check for horizontal wins
    for(int i = 0; i < 3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
    }

    // Check for vertical wins
    for(int i = 0; i < 3; i++){
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
    }

    // Check for diagonal wins
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }

    // No winner found
    return false;
}

bool boarFull(string board[]){
    bool empty = false;
    for(int i=0; i<3; i++){
        if(board[i][0] == ' ' or board[i][1] == ' ' or board[i][2] == ' '){
            empty = true;
            break;
        }
    }
    if(empty == true){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    string board[3] = {{"   "}, {"   "}, {"   "}}; // initialize the board

    cout<<"Welcome to Tic Tac Toe!"<<endl<<endl;
    cout<<"Player 1 (X) - Player 2 (O)"<<endl<<endl;

    int turn = 1; // player 1 goes first
    int row, col;

    while(true){
        // Print the board
        print_board(board);

        // Get player's move
        cout<<"Player "<<turn<<", enter your move (row column): ";
        cin>>row>>col;

        // Check if the move is valid
        if(row < 1 || row > 3 || col < 1 || col > 3){
            cout<<"Invalid move, please try again."<<endl;
            continue;
        }
        if(board[row-1][col-1] != ' '){
            cout<<"That spot is already taken, please try again."<<endl;
            continue;
        }

        // Place the mark on the board
        if(turn == 1){
            board[row-1][col-1] = 'X';
        }
        else{
            board[row-1][col-1] = 'O';
        }

        // Check if the game is over
        if(check_win(board, 'X')){
            print_board(board);
            cout<<"Player 1 (X) wins!"<<endl;
            break;
        }
        else if(check_win(board, 'O')){
            print_board(board);
            cout<<"Player 2 (O) wins!"<<endl;
            break;
        }
        else if(boarFull(board)){
            print_board(board);
            cout<<"Draw"<<endl;
            break;
        }
        else{
            if(turn == 1){
                turn = 2;
            }
            else{
                turn = 1;
            }
        }
    }
    return 0;
}
