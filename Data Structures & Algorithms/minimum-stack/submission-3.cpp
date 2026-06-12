class MinStack {
     stack<long long> st;
     long long mini=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
      if(st.empty()){
        st.push(val);
        mini=min(mini,1LL*val);
      }
      else{
        if(val>=mini) st.push(val);
        else{
          long long newval=2*1LL*val-mini;
          st.push(newval);
          mini=val;
        }
      }
        
    }
    
    void pop() {
      if(st.empty()) return;
      if(st.top()>=mini) st.pop();
      else{
        mini=2*1LL*mini-st.top();
        st.pop();
      }
      if(st.empty()) mini=INT_MAX;
        
    }
    
    int top() {
      if(st.top()>=mini) return st.top();
      else return mini;
        
    }
    
    int getMin() {
        return mini;
    }
};
