class MedianFinder {
public:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if(leftHeap.empty() || num <= leftHeap.top()) leftHeap.push(num);
        else rightHeap.push(num);
        
        if(leftHeap.size() > rightHeap.size() + 1) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        } 
        else if(rightHeap.size() > leftHeap.size()) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftHeap.size() == rightHeap.size()) 
            return (leftHeap.top() + rightHeap.top()) / 2.0;
        return leftHeap.top();
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */