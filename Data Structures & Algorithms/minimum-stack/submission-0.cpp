class MinStack {
        vector <int> st;
        vector <int> minst;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(minst.empty())
        minst.push_back(val);
        else if(val <= minst.back())
        minst.push_back(val);
        else
        minst.push_back(minst.back());
    }
    
    void pop() {
        
        minst.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minst.back();
    }
};
