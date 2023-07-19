class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
         uint32_t size = sizeof(n) * 8;
    uint32_t reversed = 0;
    for(int i = 0; i < size; i++) 
        reversed |= (((n >> i) & 1 ) << size - i - 1);
    return reversed;
    }
};