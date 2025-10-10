#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();
        int ans = INT_MIN;
        vector<bool> vis(n , false);

        for(int i =  0 ; i < n ; i++){

            if(vis[i]) continue;
            
            int x = 0;
            int j = i;

            while(j < n){
                vis[j] = true;
                x += energy[j];
                x = max(x , energy[j]);
                j += k;
            }

            ans = max(ans , x);

        }

        return ans;

    }
};

int main() {
    
    return 0;
}
