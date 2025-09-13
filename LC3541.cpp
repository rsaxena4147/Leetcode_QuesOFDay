#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowel;
        unordered_map<char,int> consonant;

        for(char ch : s){
            if(ch == 'a' or ch == 'i' or ch == 'e' or ch == 'o' or ch == 'u'){
                vowel[ch]++;
            }else{
                consonant[ch]++;
            }

        }
        int v = 0;
        int c = 0;

        for(auto a : vowel){
            v = max(v,a.second);
        }
           for(auto a : consonant){
            c = max(c,a.second);
        }
       
        

        return c+v;
    }
};