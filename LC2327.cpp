#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        
        dp[1] = 1;  

        int shareable = 0;
        
        for (int day = 2; day <= n; day++) {
            if (day - delay >= 1) {
                shareable = (shareable + dp[day - delay]) % MOD;
            }
            
            if (day - forget >= 1) {
                shareable = (shareable - dp[day - forget] + MOD) % MOD;
            }
            
            dp[day] = shareable;
        }
        
        int result = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};


int main() {
    
    return 0;
}
