#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {

        int i = 0;

        int count = 1;
        char ch ;
        int ans = INT_MIN;

        while(i+1 < num.length()){
            

            if(num[i]==num[i+1]){
                count++;
                ch = num[i];
                
            }else{
                count = 1;
                
            }

            if(count==3){
               ans = max(ans , ch-'0');
            }

            i++;
        }
        string s = "";

        if(ans != INT_MIN ){
            return string(3, ans + '0'); 
        }
        return s ;
        
    }
};