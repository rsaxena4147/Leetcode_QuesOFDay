#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class MovieRentingSystem {
public:
    int num ;
    unordered_map<int , set<pair<int,int>>> available; // movie -> {price, shop}

    

    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[2] != b[2]) return a[2] < b[2]; // price
            if (a[0] != b[0]) return a[0] < b[0]; // shop
            return a[1] < b[1];                   // movie
        }
    };
    set<vector<int>, cmp> rented; // only rented movies

    unordered_map<long long,int> priceMap; // shop,movie -> price

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        num = n;
        for(auto &e : entries){
            int shop = e[0], movie = e[1], price = e[2];
            available[movie].insert({price,shop});
            priceMap[(long long)shop*10001 + movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int count = 0;
        for(auto &x : available[movie]){
            if(count == 5) break;
            res.push_back(x.second);
            count++;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[(long long)shop*10001 + movie];
        available[movie].erase({price,shop});
        rented.insert({shop,movie,price});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[(long long)shop*10001 + movie];
        rented.erase({shop,movie,price});
        available[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = 0;
        for(auto &x : rented){
            if(count == 5) break;
            ans.push_back({x[0],x[1]});
            count++;
        }
        return ans;
    }
};
