class MedianFinder {
   priority_queue<int> sh, lh;
public:    
    void addNum(int num) 
    {
        lh.push(-num);
        sh.push(-lh.top());
        lh.pop();
        
        if (sh.size() > lh.size())
            lh.push(-sh.top()), sh.pop();
    }
    
    double findMedian() 
    {
        if (sh.size() == lh.size())
            return (sh.top() - lh.top()) / 2.0;
        return -lh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */