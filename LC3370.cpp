#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool solve(int i){

        while( i > 1){
         
            if(i%2 == 0){
                return false;
            }
            i = i / 2;
        }
        return true;
    }
    int smallestNumber(int n ) {

        int i = n;

        while(i >= n){
           if(solve(i)){
            return i;
           }
           i++;
        }
        return -1;
    }
};