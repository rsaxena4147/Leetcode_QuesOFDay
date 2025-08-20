#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>>dp;

    int solve(int i , int j , vector<vector<int>>& mat){
        if(i >= mat.size() || j >= mat[0].size()) return 0;
        if(mat[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = min(1+solve(i,j+1,mat) , min(1+solve(i+1,j,mat), 1+solve(i+1,j+1,mat)));
    }
    int countSquares(vector<vector<int>>& mat) {
        dp.resize(mat.size() , vector<int>(mat[0].size() , -1));

        int ans = 0;

        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[0].size() ; j++){

                ans+=solve(i,j,mat);
            }
        }
        return ans;
        
    }
};