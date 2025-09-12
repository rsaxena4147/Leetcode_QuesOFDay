#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        
        int vowel = 0;

        for(auto ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowel++;
        }

        if(vowel == 0) return false;
        else return true;

    }
};