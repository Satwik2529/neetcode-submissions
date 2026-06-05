class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size()==0) return "";
        string ans="";
        for(int i=0;i<strs.size();i++){
            int len=strs[i].size();
            ans=ans+to_string(len);
            ans.push_back('#');
            ans=ans+strs[i];
        }
        return ans;
    }
  
    vector<string> decode(string s) {
        if(s.size()==0) return {};
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            i=j+1;
            ans.push_back(s.substr(i,len));
            i=i+len;
        }
        return ans;
    }
};
