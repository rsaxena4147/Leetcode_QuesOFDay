#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int num, int ex) {
        int drink = num;
        int empty = num;
        int curr = 0;

        while(empty >= ex) {
            empty = empty - ex;
            empty+=1;
            ex += 1;
            drink += 1;
        }
        return drink;
    }
};