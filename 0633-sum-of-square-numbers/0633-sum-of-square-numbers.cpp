class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long  i = 0 ; (i * i) <= c ; i++)
        {
            // long long j = c - (i * i);
            // double r = sqrt(j);
            // int r1 = (int)r;
            // if(r == r1) return true;

            long long remaining = c - (i * i);
            long long sqrtRemaining = static_cast<long long>(sqrt(remaining));
            if (sqrtRemaining * sqrtRemaining == remaining)  return true;
        }

        return false;
    }
};