#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
           if(numerator == 0) return "0";

        string ans = "";

        if((numerator < 0) ^ (denominator < 0)) ans += '-';

        long long n = llabs(numerator);
        long long d = llabs(denominator);

        ans += to_string(n / d);

        long long rem = n % d;

        if(rem == 0) return ans;
        ans += '.';

        unordered_map<long long  , int> mp;

        while(rem != 0){
            
            if(mp.count(rem)){
                ans.insert(mp[rem] , "(");
                ans += ")";
                return ans;
            }

            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;


        }


        return ans;
    }
};