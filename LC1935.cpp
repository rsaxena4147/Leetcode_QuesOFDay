#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        vector<string> store;
        string st = "";
        for(char ch : text){
            if(ch == ' '){
                store.push_back(st);
                st="";
            }else{
                st+=ch;
            }
        }
        if(st.length()) store.push_back(st);

        set<char> s;
        for(int i = 0 ; i < brokenLetters.size() ; i++ ){
            s.insert(brokenLetters[i]);
        }
        int count = 0;
        for(int i = 0 ; i < store.size() ; i++){
            bool flag = 0;
            for(int j = 0 ; j < store[i].size() ; j++){

                if(s.count(store[i][j]) >= 1){
                    flag = 1;
                }
            }
            if(flag == 0){
                count++;
            }
        }

        return count;
    }
};