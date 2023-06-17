class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        vector<int>h;
        while(q.size()){
            h.push_back(q.front());
            q.pop();
        }
        q.push(x);
        for(int i=0;i<h.size();i++){
            q.push(h[i]);
        }
    }
    
    int pop() {
        int k=q.front();
        q.pop();
        return k;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return !q.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */