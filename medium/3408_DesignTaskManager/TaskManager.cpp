class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task: tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        priorityMap[taskId] = priority;
        ownerMap[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        priorityMap[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        priorityMap[taskId] = -1;
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto task = pq.top();
            pq.pop();
            if (task.first == priorityMap[task.second]) {
                priorityMap[task.second] = -1;
                return ownerMap[task.second];
            }
        }
        return -1;
    }
private:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> priorityMap;
    unordered_map<int, int> ownerMap;

};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */