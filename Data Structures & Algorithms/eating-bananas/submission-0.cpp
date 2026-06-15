class Solution {
   public:
    int check(vector<int>& piles, int mid) {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] + mid - 1) / mid;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int a = 1;
        int b = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while (a <= b) {
            int mid = a + (b - a) / 2;
            if (check(piles, mid) >h) {
               

                a = mid + 1;

            } else {
                 ans =mid;
                b = mid - 1;
            }
        }
        return ans;
    }
};
