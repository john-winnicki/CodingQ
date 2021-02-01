class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> big;
    priority_queue<int> small;
    MedianFinder() {
    }
    
    void addNum(int num) {
        int topper;
        if(small.size()==0){
            small.push(num);
            return;
        }
        
        if(big.size()!=small.size()){
            topper = small.top();
            small.pop();
        }
        else{
            topper = big.top();
            big.pop();
        }
        small.push(min(topper, num));
        big.push(max(topper, num));
    }
    
    double findMedian() {
        
        if(small.size()==big.size()) return (small.top()+big.top())/2.0;
        else return small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */