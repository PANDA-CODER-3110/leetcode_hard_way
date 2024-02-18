#define ll long long
#define pll pair<ll,ll> 
class Solution {
public:
    int mostBooked(int R, vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        vector<int> rooms(R, 0);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        priority_queue<int, vector<int>, greater<int>> av_rooms;
        for(int i=0; i<R; i++) av_rooms.push(i);

        for(auto m : A) {
            ll start = m[0], end = m[1];
            while(!pq.empty() and pq.top().first<=start) {
                auto [old_end, room] = pq.top(); pq.pop();
                av_rooms.push(room);
            }
            if(!av_rooms.empty()) {
                int room = av_rooms.top(); av_rooms.pop();
                pq.push({end, room});
                rooms[room]++;
            }
            else {
                auto [old_end, room] = pq.top(); pq.pop();
                pq.push({end+old_end-start, room});
                rooms[room]++;
            }
        }
        return max_element(rooms.begin(), rooms.end()) - rooms.begin();
    }
};