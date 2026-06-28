class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            int k=abs(a-b);
            if(k!=0) pq.push(k);
        }
        if(pq.size()==0) return 0;
        return pq.top();
        
    }
};
