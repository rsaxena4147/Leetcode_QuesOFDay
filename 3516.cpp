#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dis1 = abs(z-x);
        int dis2 = abs(z - y);

        if(dis1 == dis2) return 0;

        return dis1 > dis2 ? 2 : 1;
        
    }
};