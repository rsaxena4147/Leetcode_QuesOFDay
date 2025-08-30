#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {

            unordered_map<char, int> freq;
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '.')
                    continue;
                if (freq.find(board[i][j]) != freq.end()) {
                    return false;
                }

                freq[board[i][j]]++;
            }
        }

        for (int i = 0; i < col; i++) {

            unordered_map<char, int> freq;
            for (int j = 0; j < row; j++) {
                if (board[j][i] == '.')
                    continue;
                if (freq.find(board[j][i]) != freq.end()) {
                    return false;
                }

                freq[board[j][i]]++;
            }
        }

        for (int i = 0; i < row; i += 3) {
            for (int j = 0; j < col; j += 3) {

                unordered_map<char, int> freq;

                for (int stR = i; stR < i + 3; stR++) {
                    for (int stC = j; stC < j + 3; stC++) {
                        if (board[stR][stC] == '.')
                            continue;
                        if (freq.find(board[stR][stC]) != freq.end())
                            return false;
                        freq[board[stR][stC]]++;
                    }
                }
            }
        }
        return true;
        }
    };