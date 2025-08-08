#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    double solve(int a , int b , vector<vector<double>> &dp){

        if(a<=0 && b<= 0)
        return 0.5;
        else if(a<=0)
        return 1;
        else if(b<=0)
        return 0;

        if(dp[a][b]!=-1)
        return dp[a][b];

        dp[a][b]=0.25* (solve(a - 100, b - 0, dp) + solve(a - 75, b - 25 , dp) +
                       solve(a - 50, b - 50 , dp) + solve(a - 25, b - 75 , dp));
        
        return dp[a][b];
    }

    double soupServings(int n) {

        if(n>5000)
        return 1;

        
        vector<vector<double>>dp(n+1 , vector<double>(n+1,-1));
        return solve(n,n,dp);
    }
};