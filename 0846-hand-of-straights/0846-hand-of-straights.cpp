class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> mp;
        for (auto X : hand) mp[X]++;

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int current = it->first;
            int count = it->second;

            if (count > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (mp[current + i] < count) return false;
                    mp[current + i] -= count;
                }
            }
        }
        return true;

    }
};