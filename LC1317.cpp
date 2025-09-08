#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {

        int i = 1;

        while(i < n){
            string st = to_string(i);
            string st2 = to_string(n-i);



            auto pos = st.find('0');
            auto pos2 = st2.find('0');

            if(pos == std::string::npos && pos2 == std::string::npos ){
                return {i,n-i};
            }else{
                i++;
            }
        }
        return {-1,-1};
    }
};