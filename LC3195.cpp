#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int rowMin = INT_MAX;
        int rowMax = INT_MIN;
        int colMin = INT_MAX;
        int colMax = INT_MIN;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){

               

                if(grid[i][j]==1){
                    rowMin = min(rowMin , i);
                    rowMax = max(rowMax , i);
                    colMin = min(colMin , j);
                    colMax = max(colMax , j);
                }



            }
        }
        
        return (rowMax - rowMin + 1) * (colMax - colMin + 1);
    }
};