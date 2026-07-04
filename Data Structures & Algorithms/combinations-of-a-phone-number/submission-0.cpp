class Solution {
public:
vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> ans;
void dfs(int index,string digits,string temp){
    if(index==digits.size()){
         ans.push_back(temp);
         return;
    }
    string hi=mp[digits[index]-'0'];
    for(int i=0;i<hi.size();i++){
        temp.push_back(hi[i]);
        dfs(index+1,digits,temp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string temp="";
       dfs(0,digits,temp);
       return ans;
        
    }
};
