class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n==0) return n;
        uint32_t curr = 0;
        int counter = 0;
        while(n!=0){
            uint32_t dig1 = n&1;
            curr = (curr<<1)|dig1;
            n = n>>1;
            counter++;
        }
        // return curr;
        return curr<<(32-counter);
        
    }
};