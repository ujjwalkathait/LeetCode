class TaskManager {
    unordered_map<int,pair<int,int>> taskToDetails;
    set<pair<int,int>> pq; // <priority,taskid>
    
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0;i<tasks.size() ; i++){
            taskToDetails[tasks[i][1]] = {tasks[i][2],tasks[i][0]};
            pq.insert({tasks[i][2],tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToDetails[taskId] = {priority,userId};
        pq.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int prev = taskToDetails[taskId].first;
        int user = taskToDetails[taskId].second;
        taskToDetails[taskId] = {newPriority,user};
        pq.erase({prev,taskId});
        pq.insert({newPriority,taskId});
        
    }
    
    void rmv(int taskId) {
        int priority = taskToDetails[taskId].first;
        pq.erase({priority,taskId});
        taskToDetails.erase(taskId);
    }
    
    int execTop() {
        if(pq.size() == 0) return -1;
        pair<int, int> highest = *(pq.rbegin());
        int user = taskToDetails[highest.second].second;
        rmv(highest.second);
        return user; 
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