class TimeMap {
   unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key , int timestamp) {
       if(mp.find(key)==mp.end()) return "";
       vector<pair<int,string>> &k=mp[key];  
       int ans=-1;
       int low=0;
       int high=k.size()-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(k[mid].first<=timestamp){
                ans=mid;
                low=mid+1;
        }
        else{
            high=mid-1;
        }
       }  
       return ans==-1?"":mp[key][ans].second; 
        
    }
};
