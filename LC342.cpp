#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n==1 or n==0) return n;
        if(n<0 or n%4!=0) return 0;
        return isPowerOfFour(n/4);

        
    }
};