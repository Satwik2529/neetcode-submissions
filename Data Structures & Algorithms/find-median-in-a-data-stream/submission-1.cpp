class MedianFinder {
public:
 priority_queue<int> pq;
 priority_queue<int,vector<int>,greater<int>>pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.size()==0||num<pq.top()){
               pq.push(num);
        }
        else {
            pq1.push(num);
        }

        if(pq.size()>pq1.size()+1){
            
             pq1.push(pq.top());
            pq.pop();
        }
        else if(pq1.size()>pq.size()){
           pq.push(pq1.top());
            pq1.pop();
        }

        
    }
    
    double findMedian() {
        if(pq1.size()==pq.size()){
            double a =pq.top()+pq1.top();
            a=a/2;
            return a;
        }
        else return pq.top();
        
        
    }
};
