class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int totalsubsets = 1 << n;
        int maxsize = 0;
        int maxOr = 0, count = 0;
        for (int i = 0; i < totalsubsets; i++) {
            int val = i;
            vector<int> inner;
            int k = 0;
            int tempOr = 0;
            while (val) {
                if (val & 1) {
                     tempOr |= nums[k];
                }
                k++;
                val >>= 1;
            }
           
            if (tempOr > maxOr) {
                maxOr = tempOr;
                count = 1;
            } else if (tempOr == maxOr) {
                count++;
            }
        }
        return count;
    }
};