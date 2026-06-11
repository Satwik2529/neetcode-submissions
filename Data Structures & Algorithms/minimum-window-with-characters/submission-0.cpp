class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        map<int,int> mp1;
        int minlen = INT_MAX;
        string res = "";

        for(int i = 0; i < t.size(); i++){
            mp1[t[i]]++;
        }

        for(int i = 0; i < s.size(); i++){
            map<int,int> mp2;

            for(int j = i; j < s.size(); j++){
                mp2[s[j]]++;

                bool ans = true;

                for(auto it : mp1){
                    if(mp2[it.first] < it.second){
                        ans = false;
                        break;
                    }
                }

                if(ans){
                    int len = j - i + 1;

                    if(len < minlen){
                        minlen = len;
                        res = s.substr(i, len);
                    }
                }
            }
        }

        return res;
    }
};