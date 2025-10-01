#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int num, int ex) {
        int filled = num;
        int empty = num;
        int curr = num;

        while(empty >= ex){
            curr = floor(empty/ex);
            empty = (empty%ex)+curr;
            filled += curr;
        }

        return filled;
    }
};