class MedianFinder {
public:
    // 최대 -> 최소 순서대로 저장되는 maxPQ : median 좌측
    // 최소 -> 최대 순서대로 저장되는 minPQ : median 우측
    priority_queue<int, vector<int>>                maxPQ;
    priority_queue<int, vector<int>, greater<int>>  minPQ;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxPQ.push(num);
        int tmp = maxPQ.top();
        maxPQ.pop();
        minPQ.push(tmp);

        //minPQ의 사이즈는 항상 maxPQ의 사이즈보다 작아야한다.
        if(minPQ.size() > maxPQ.size()){
            tmp = minPQ.top();
            minPQ.pop();
            maxPQ.push(tmp);
        }
    }
    
    double findMedian() {   
        if(maxPQ.size() > minPQ.size()) return maxPQ.top();
        return (maxPQ.top() + minPQ.top()) /2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
