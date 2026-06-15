class TimeMap {
   unordered_map<string,unordered_map<int,string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key , int timestamp) {
        int ans=-1;
        for(auto it:mp[key]){
            if(it.first<=timestamp){
               ans = max(ans, it.first);  }

        }
        return mp[key][ans];
       
        
    }
};
