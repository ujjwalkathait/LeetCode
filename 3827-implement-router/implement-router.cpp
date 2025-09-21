class Router {
public:
    deque<tuple<int,int,int>> dq;
    set<tuple<int,int,int>> st; 
    unordered_map<int, vector<int>> mp;
    int limit;
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    //you have exactly 8 mins 
    bool addPacket(int source, int destination, int timestamp) {
        if(st.find({source,destination,timestamp}) == st.end() && dq.size() <= limit){
            if(dq.size() == limit){
                //remove the first entry
                auto arr = dq.front();
                int destination = get<1>(arr);
                st.erase(arr);
                mp[destination].erase(mp[destination].begin());
                dq.pop_front();
            }
            st.insert({source,destination,timestamp});
            mp[destination].push_back(timestamp);
            dq.push_back({source,destination,timestamp});
            return true;
        }
        return false;
    }
    
    vector<int> forwardPacket() {
        if(dq.empty()) return {};
        auto arr = dq.front();
        int destination = get<1>(arr);
        dq.pop_front();
        mp[destination].erase(mp[destination].begin());
        st.erase(arr);
        return { get<0>(arr), get<1>(arr), get<2>(arr) };
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto low = lower_bound(mp[destination].begin(), mp[destination].end(), startTime);
        auto up = upper_bound(mp[destination].begin(), mp[destination].end(), endTime);
        return up - low;
    }
};
/* you phele nahake aaying then we continuing okay to optimize it, then khane ka time houing, after khana but we are spending way too much time on one ques we have one more ques to do and tomorrow i have a mock, b

start = 95
end = 115
low(95) >= x(95)
up(120) > x(115)
5 -> {90,95, 105, 110, 115, 115, 115, 120};
low = 1;
up = 3
3 - 1 = 2

*/
/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */