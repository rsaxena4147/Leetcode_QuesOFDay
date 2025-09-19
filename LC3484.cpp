#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Spreadsheet {
public:
    vector<vector<int>> sheet;
    int rows;
    Spreadsheet(int rows) {
        sheet.resize(rows+1, vector<int>(26, 0));
        this->rows = rows;
    }

    void setCell(string cell, int value) {
        char ch = cell[0];
        int y = stoi(cell.substr(1, cell.length()));
        int x = (int)ch - 65;
        sheet[y-1][x] = value;
    }

    void resetCell(string cell) {
        char ch = cell[0];
        int y = stoi(cell.substr(1, cell.length()));
        int x = (int)ch - 65;
        sheet[y-1][x] = 0;
    }

    int getValue(string formula) {
        string x = "";
        string y = "";
        bool flag = 0;

        for (int i = 1; i < formula.size(); i++) {
            if (formula[i] == '+') {
                flag = 1;
                continue;
            }
            if (flag == 1) {
                y += formula[i];

            } else {
                x += formula[i];
            }
        }

        if (x[0] >= '0' and x[0] <= '9' and y[0] >= '0' and y[0] <= '9') {
            return stoi(x) + stoi(y);
        } else if (x[0] >= '0' and x[0] <= '9' and y[0] >= 'A' and
                   y[0] <= 'Z') {
            char ch = y[0];
            int b = stoi(y.substr(1, y.length()));
            int a = (int)ch - 65;

            return stoi(x) + sheet[b-1][a];
        } else if (y[0] >= '0' and y[0] <= '9' and x[0] >= 'A' and
                   x[0] <= 'Z') {
            char ch = x[0];
            int b = stoi(x.substr(1, x.length()));
            int a = (int)ch - 65;

            return stoi(y) + sheet[b-1][a];
        } else {
            char ch = x[0];
            int b = stoi(x.substr(1, x.length()));
            int a = (int)ch - 65;

            char c = y[0];
            int n = stoi(y.substr(1, y.length()));
            int m = (int)c - 65;
           

            return sheet[n-1][m] + sheet[b-1][a];
        }

        return 1;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */