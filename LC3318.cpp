#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;

        int n = nums.size();
       
        int r = 0, l =0;
        unordered_map<int,int> map;
        bool flag = 0;

        while(r < n){
            map[nums[r]]++;
            int size = r - l + 1;
            if(size == k){
                flag = 1;
                priority_queue<pair<int,int>> pq;

                for(auto p : map){
                    pq.push({p.second,p.first});
                    
                }

                int count = x;
                int sum = 0;

                while(count-- && !pq.empty()){
                    auto [a,b] = pq.top();
                    pq.pop();
                    sum += a*b;
                }
                ans.push_back(sum);
                map[nums[l]]--;
                
                if(map[nums[l]]==0){
                    map.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        if(flag == 0){
            ans.push_back(accumulate(nums.begin() , nums.end() , 0));
         

        }
        return ans;
    }
};