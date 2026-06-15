class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int k=nums1.size();
            k=k+nums2.size();
        int r=k;
            k=k/2;
            k=k+1;
             priority_queue<int,vector<int>,greater<int>> pq;
             for(int i=0;i<nums1.size();i++){
                pq.push(nums1[i]);
                while(pq.size()>k) pq.pop();
             }
             for(int i=0;i<nums2.size();i++){
                pq.push(nums2[i]);
                while(pq.size()>k) pq.pop();
             }
             if(r%2==1){
                return pq.top();
             }
             else{
                double q=pq.top();
                pq.pop();
                double r=pq.top();
                pq.pop();
                return (q+r)/2;
             }
             return 0;
    }
};
