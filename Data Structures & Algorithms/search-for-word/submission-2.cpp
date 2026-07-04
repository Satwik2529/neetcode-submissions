class Solution {
public:
bool found=false;
void dfs(vector<vector<char>> &board,string word,int i,int j,string ans){
    if(found) return;
    if(ans==word){
         found=true;
         return;
    }
    if(i>=board.size()||j>=board[0].size()||i<0||j<0){
        return;
    }
    if(board[i][j]=='#') return;
    if (ans != word.substr(0, ans.size()))
       return;
    ans=ans+board[i][j];
    char ch=board[i][j];
    board[i][j]='#';
    dfs(board,word,i+1,j,ans);
    dfs(board,word,i-1,j,ans);
    dfs(board,word,i,j+1,ans);
    dfs(board,word,i,j-1,ans);
    board[i][j]=ch;
    ans.pop_back();

}
    bool exist(vector<vector<char>>& board, string word) {
        string ans="";
        char s=word[0];
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               if(board[i][j]==s){
                  dfs(board,word,i,j,ans);
               }
            }
        }
        return found;
        
    }
};
