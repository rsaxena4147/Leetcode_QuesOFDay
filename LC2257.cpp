#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int row, col;
    bool check(int i, int j) {
        if (i >= 0 and i < row and j >= 0 and j < col) {
            return true;
        }
        return false;
    }
    void helper(int i, int j, vector<vector<int>>& grid) {

        // up
        int x = i - 1, y = j;
        while (check(x, y) && grid[x][y] != -1 && grid[x][y] != -2) {
            grid[x][y]++;
            x--;
        }

        // down
        x = i + 1;
        y = j;
        while (check(x, y) && grid[x][y] != -1 && grid[x][y] != -2) {
            grid[x][y]++;
            x++;
        }

        // left
        x = i;
        y = j - 1;
        while (check(x, y) && grid[x][y] != -1 && grid[x][y] != -2) {
            grid[x][y]++;
            y--;
        }

        // right
        x = i;
        y = j + 1;
        while (check(x, y) && grid[x][y] != -1 && grid[x][y] != -2) {
            grid[x][y]++;
            y++;
        }
    }
    void solve(vector<vector<int>>& grid, vector<vector<int>>& guards) {

        for (int i = 0; i < guards.size(); i++) {

            helper(guards[i][0], guards[i][1], grid);
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        row = m, col = n;
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = -2; //-2 -> guard
        }
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = -1; //-1 -> walls
        }

        solve(grid, guards);
        int count=0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};