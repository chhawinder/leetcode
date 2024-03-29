/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int>q;
    void help(vector<NestedInteger> &nl){
        for(int i=0;i<nl.size();i++){
            if(nl[i].isInteger()){
                q.push(nl[i].getInteger());
            }else{
                help(nl[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nl) {
        help(nl);
        
    }
    
    int next() {
        if(q.size()){
            int k=q.front();
            q.pop();
            return k;
        }
        return -1;
    }
    
    bool hasNext() {
        return q.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */