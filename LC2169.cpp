#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        if(num1 == 0 or num2 == 0){
                return 0;
            }

        while(num1 != 0 or num2 != 0){
            if(num1 > num2){
                
                
                num1 -= num2;
            }else{
                num2 -= num1;
            }

            count++;
            if(num1 == 0 or num2 == 0){
                break;
            }
        }
        return count;
    }
};