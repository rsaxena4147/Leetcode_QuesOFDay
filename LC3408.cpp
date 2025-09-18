#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TaskManager {
public:
    set<pair<int, pair<int, int>>> map;      // p->taskId , userId
    unordered_map<int, pair<int, int>> map2; // task-> userId , priority
    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            map.insert({-tasks[i][2], {-tasks[i][1], -tasks[i][0]}});
            map2[tasks[i][1]] = {tasks[i][0], tasks[i][2]};
        }
    }

    void add(int userId, int taskId, int priority) {
        map.insert({-priority, {-taskId, -userId}});
        map2[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority) {

        auto& [u, p] = map2[taskId];
        map.erase({-p, {-taskId, -u}});
        map.insert({-newPriority, {-taskId, -u}});
        map2[taskId] = {u,newPriority};
    }

    void rmv(int taskId) {
        auto& [u, p] = map2[taskId];
        map.erase({-p, {-taskId, -u}});

        map2.erase(taskId);
    }

    int execTop() {
        if (map.empty())
            return -1;

        
        auto [nt, nu] = map.begin()->second;

        rmv(-nt);
        return -nu;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */