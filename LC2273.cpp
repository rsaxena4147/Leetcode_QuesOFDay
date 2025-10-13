#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string a , string b){
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());

        if(a == b) return true;

        return false;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        for(int i = n - 1 ; i > 0 ; i--){
            if(isAnagram(words[i] , words[i-1])){
                words.erase(words.begin() + i);
            }
        }
        return words;
    }
};