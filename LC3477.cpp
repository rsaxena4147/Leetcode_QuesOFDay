#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        vector<bool> isfilled(baskets.size() , 0);
        int ans = 0;

        for(int i = 0 ; i < fruits.size() ; i++ ){
            for(int j = 0 ; j < baskets.size() ; j++){

                if(baskets[j] >= fruits[i] && isfilled[j]==0){
                    isfilled[j]=1;
                    ans++;
                    break;
                }
            }
        }

        return fruits.size()-ans;
    }
};