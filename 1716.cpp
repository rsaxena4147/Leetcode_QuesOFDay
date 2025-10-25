#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {

        int count = 1;
        int day = 1;
        int sum = 0;
        int i = 1;
        int c = 1;

        while(c <= n){
            if(count == 8){
                i = day + 1;
                day = day + 1;
                count = 1;
            }
            sum += i;
            i++;
            count +=1;
            c++;
        }
        return sum;
    }
};