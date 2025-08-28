#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> diagonalOrder(int i, int j, vector<vector<int>>& mat) {
        vector<int> st;
     

        while (i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size()) {
            st.push_back(mat[i][j]);
           
            i++;
            j++;
        }

        return st;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        //lower trinangle -> decreasing order;

        for(int i = 0; i < row ; i++ ){
            vector<int> store = diagonalOrder(i,0,grid);

            int r = i;
            int c = 0;
            sort(store.begin() ,store.end() ,  greater<int>());
            int ind = 0;

            while(r < row && c < col && ind < store.size()){
                grid[r++][c++]=store[ind++];          
            }
        }

        //upper triangle -> ascending order;

         for(int i = 1; i < col ; i++ ){
            vector<int> store = diagonalOrder(0,i,grid);

            int r = 0;
            int c = i;
            sort(store.begin() ,store.end());
            int ind = 0;

            while(r < row && c < col && ind < store.size()){
                grid[r++][c++]=store[ind++];          
            }
        }
        return grid;
    }
};