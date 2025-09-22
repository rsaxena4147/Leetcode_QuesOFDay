#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxi = INT_MIN;
        for(auto x : nums){
            freq[x]++;
            maxi = max(maxi , freq[x]);
        }
        int ans=0;
        for(auto& x : freq){
            if(x.second == maxi){
                ans += x.second;
            }
        }
        return ans;
    }
};