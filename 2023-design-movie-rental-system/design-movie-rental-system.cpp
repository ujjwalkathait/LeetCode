// class MovieRentingSystem {
//     set<pair<int,int>> shopToMovie;
//     set<pair<int, int>> priceToShop;
//     unordered_map<int,set<pair<int,int>>> moviesToDetails; 
//     moviesToDetails[shopToMovie.seocnd]  = {prices, shop}
    
// public:
// // we would have to make one comparator function, see we would need one comparator for ascending order of shops(search function) and other comparator for ascending order of movies (report function)
// //no need we can have a  set of <shop,movie> to check if a movie is rented see if it exist in the set, to drop it erase it from the set
// //jaldi likh na code
//     MovieRentingSystem(int n, vector<vector<int>>& entries) {
//         for(int i = 0 ;i < entries.size(); i++){
//             moviesToDetails[entries[i][1]].insert({entries[i][2],entries[i][0]});
//         }
//     }
    
//     vector<int> search(int movie) {
//         //chepest 5 shops with prices in ascending right?
//         vector<int> ans;
//         for(auto x: moviesToDetails[movie]){
//             if(shopToMovie.find({x.second,movie}) == shopToMovie.end()){
//                 ans.push_back(x.second);
                
//             }
//         }
//         return ans;
//     }
//     //4:20 pm
//     //khud kar le solve
//     //bhyi kya kar ra haoi jaldi kar
//     //mai kar lunga baad me bye
//     //ek baar mummy uth gayi to mai nahi let paungawe
//     // moteeeee
//     void rent(int shop, int movie) {
//         int price = moviesToDetails[movie].first;
//         priceToShop.insert({,shop}); 
//         shopToMovie.insert({shop,movie});
//     }
    
//     void drop(int shop, int movie) {
//         shopToMovie.erase({shop,movie});
//     }
    
//     vector<vector<int>> report() {
//         //chepest 5 movies with prices in ascending order
    
//         // {price, shop}
//     }
// };
// //no not only the return value differs but both are asking movies based on different conditions which i listed above
// //how would you approach this problem
// /*
// MovieRentingSystem(int n, int[][] entries) Initializes the MovieRentingSystem object with n shops and the movies in entries.
// shops = 0, 1, 2
// movies = 1,2,3
// movieRentingSystem.search(1);  // return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. Shop 1 is cheapest; shop 0 and 2 are the same price, so order by shop number.
// // [0,1,5] 
// [0,2,6] - 
// [0,3,7]

// [1,1,4] 
// [1,2,7] - 

// [2,1,5] 
// */
// /**
//  * Your MovieRentingSystem object will be instantiated and called as such:
//  * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
//  * vector<int> param_1 = obj->search(movie);
//  * obj->rent(shop,movie);
//  * obj->drop(shop,movie);
//  * vector<vector<int>> param_4 = obj->report();
//  */

using int2=pair<int,int>;           // (price, shop)
using int3=tuple<int,int,int>;      // (price, shop, movie)

class MovieRentingSystem {
public:
    unordered_map<uint64_t,int> Shop;      // (shop,movie)->price
    unordered_map<int,set<int2>> Movie;    // movie->set(price,shop)
    set<int3> rented;                      // rented->set (price,shop,movie)

    static inline uint64_t key(int shop,int movie) {
        return (uint64_t)shop<<32|movie;
    }

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop=e[0], movie=e[1], price=e[2];
            Shop[key(shop,movie)]=price;
            Movie[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto& S=Movie[movie];
        int i=0;
        for (auto it=S.begin(); it!=S.end() && i<5; it++, i++) {
            ans.push_back(it->second); // shop
        }
        return ans;
    }

    void rent(int shop,int movie) {
        int price=Shop[key(shop,movie)];
        Movie[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop,int movie) {
        int price=Shop[key(shop,movie)];
        Movie[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i=0;
        for (auto it=rented.begin(); it!=rented.end() && i<5; it++, i++) {
            auto [price, shop, movie]=*it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};
