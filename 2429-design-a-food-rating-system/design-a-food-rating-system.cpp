class FoodRatings {
    struct cmp{
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) const {
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int, string>, cmp>> cuisineToDetails; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToDetails[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int rating = foodToRating[food];
        cuisineToDetails[cuisine].erase({rating, food});
        cuisineToDetails[cuisine].insert({newRating, food});
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToDetails[cuisine].rbegin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */