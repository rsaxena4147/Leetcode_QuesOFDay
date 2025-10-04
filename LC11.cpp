#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0 ;
        int j = height.size()-1;

        int ans= INT_MIN;

        while( i < j){

            int b = j - i;
            int l = min(height[i] ,height[j]);

            ans = max(l*b , ans);
            if(height[i]< height[j]){
             i++;
            }else{
                j--;
            }

        }
        return ans;
    }
};