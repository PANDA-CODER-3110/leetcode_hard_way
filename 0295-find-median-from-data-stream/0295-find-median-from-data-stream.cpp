class MedianFinder {
    priority_queue<int> minHalf;
    priority_queue<int, vector<int>, greater<int>> maxHalf;
    int sz1, sz2;
public:
    MedianFinder() {
        sz1  =0, sz2 = 0;
    }
    
    void addNum(int num) {
        if(sz1 ==0 && sz2 ==0){
            minHalf.push(num);
            sz1++;
        }
        else{
            if(num <= minHalf.top()){
                minHalf.push(num);
                sz1++;
                if(sz1 > sz2+1){
                    maxHalf.push(minHalf.top());
                    sz2++;
                    minHalf.pop();
                    sz1--;
                }
            }
            else{
                maxHalf.push(num);
                sz2++;
                if(sz2 > sz1){
                    minHalf.push(maxHalf.top());
                    sz1++;
                    maxHalf.pop();
                    sz2--;
                }
            }
            
        }
    }
    
    double findMedian() {
        if((sz1 + sz2) % 2 != 0) return double( minHalf.top());

        return (minHalf.top() + maxHalf.top())/2.0;
    }
};
