class RideSharingSystem {
public:
    queue<int> riders;
    queue<int> drivers;
    unordered_set<int> cancelledRiders;
    unordered_set<int> activeRiders;

public:
    RideSharingSystem() {}
    
    void addRider(int riderId) {  
        riders.push(riderId);
        activeRiders.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while (!riders.empty() && cancelledRiders.count(riders.front())) {
            activeRiders.erase(riders.front());
            riders.pop();
        }
        
        if (riders.empty() || drivers.empty()) {
            return {-1, -1};
        }
        
        int driverId = drivers.front();
        int riderId = riders.front();
        
        drivers.pop();
        riders.pop();
        activeRiders.erase(riderId);
        
        return {driverId, riderId};
    }
    
    void cancelRider(int riderId) {
        int var = riderId;   
        
        if (activeRiders.count(var)) {
            cancelledRiders.insert(var);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */