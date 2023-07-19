class RecentCounter {
public:
     RecentCounter() {}
    
    queue<int>q;
    int ping(int t) {
        int temp=t-3000;
        q.push(t);
        while(q.front()<temp)q.pop();
        return q.size();

    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */