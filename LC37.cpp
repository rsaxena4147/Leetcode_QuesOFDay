#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSafe(int val , int r , int c , vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            if(board[r][i]==val) return 0;
            else if(board[i][c]==val) return 0;
            else if (board[3*(r/3)+i/3][3*(c/3) + i%3]==val) return 0;

        }
        return 1;
    }
    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {

                        if (isSafe(ch, i, j, board)) {
                            board[i][j] = ch;

                            bool isPoss = solve(board);

                            if (isPoss)
                                return 1;
                            else
                                board[i][j] = '.';
                        }
                    }

                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {  solve(board); }
};