class MyQueue {
public:
    
    stack<int>s;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>k;
        while(s.size()!=0){
            k.push(s.top());
            s.pop();
        }
        s.push(x);
        while(k.size()!=0){
            s.push(k.top());
            k.pop();
        }
    }
    
    int pop() {
        int p=s.top();
        s.pop();
        return p;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */