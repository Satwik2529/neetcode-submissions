class Solution {
public:
  vector<string> ans;
  void dfs(string temp,int open,int close,int n){
    if(temp.size()==2*n){
        ans.push_back(temp);
        return;
    }
    if(open<n){
        temp=temp+'(';
        dfs(temp,open+1,close,n);
        temp.pop_back();
    }
    if(close<open){
        temp=temp+')';
        dfs(temp,open,close+1,n);
        temp.pop_back();
    }
  }

    vector<string> generateParenthesis(int n) {
        string temp="";
        dfs(temp,0,0,n);
        return ans;
    }
};
