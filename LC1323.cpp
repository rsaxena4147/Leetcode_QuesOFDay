#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {

        int i = 0;

        string n = to_string(num);

        while(i<n.length()){
            if(n[i]=='6'){
                n[i]= '9';
                break;
            }
            i++;
        }
        return stoi(n);
    }
};