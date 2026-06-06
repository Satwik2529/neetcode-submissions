class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int l=0;
      int r=l+1;
      int maxpro=0;
      while(l<r&&r<prices.size()){
        if(prices[r]<prices[l]){
            l=r;
        }
        else{
           maxpro=max(maxpro,prices[r]-prices[l]);

        }
        r++;
      }
      return maxpro;
    }
};
