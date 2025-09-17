#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> menu1;
    unordered_map<string, pair<string, int>> menu2;
   
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {

        for (int i = 0; i < foods.size(); i++) {
            menu2[foods[i]] = {cuisines[i], ratings[i]};
        }

        for (int i = 0; i < cuisines.size(); i++) {
            menu1[cuisines[i]].insert({-ratings[i], foods[i]});
        }
        
    }

    // void changeRating(string food, int newRating) {
    //    auto &[cuisine, oldRating] = menu2[food];
       
    //     menu1[cuisine].erase({-oldRating, food});
      
    //     oldRating = newRating;
       
    //     menu1[cuisine].insert({-newRating, food});

       
    // }

    string highestRated(string cuisine) { return menu1[cuisine].begin()->second; }
};

// /**
//  * Your FoodRatings object will be instantiated and called as such:
//  * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
//  * obj->changeRating(food,newRating);
//  * string param_2 = obj->highestRated(cuisine);
//  */
