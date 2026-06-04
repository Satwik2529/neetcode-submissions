class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            m2[t[i]]++;
        }
        bool found=true;
        if(s.size()==t.size()){
              for(auto it:m1){
                if(m2[it.first]!=it.second){
                    found=false;
                    return false;
                }
              }
        }
        else{
            return false;
        }
        if(found) return true;
    }
};
