#include <bits/stdc++.h>
#include <iostream>
using namespace std;


#define MOD 1000000007

class Solution {
public:
    int solve(int n, int x, int num,  vector<vector<int>>&dp) {

        if (n == 0)
            return 1;

        if (n < 0)
            return 0;

        int p = pow(num, x);

        if (p > n)
            return 0;

        if (dp[n][num] != -1)
            return dp[n][num];

        int take = solve(n - p, x, num + 1,dp);
        int skip = solve(n, x, num + 1,dp);

        dp[n][num] = (take + skip)%MOD;

        return dp[n][num];
    }
    int numberOfWays(int n, int x) {
        int num = 1;
        vector<vector<int>>dp(310, vector<int>(320,-1));
        return solve(n, x, num , dp)%MOD;
    }
};