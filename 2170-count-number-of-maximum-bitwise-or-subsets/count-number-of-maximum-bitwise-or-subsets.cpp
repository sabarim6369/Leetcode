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
            while (val) {
                if (val & 1) {
                    inner.push_back(nums[k]);
                }
                k++;
                val >>= 1;
            }
            if (inner.size() == 0) {
                continue;
            } else {
                int temp = inner[0];
                for (int j = 1; j < inner.size(); j++) {
                    temp |= inner[j];
                }

                if (temp > maxOr) {
                    maxOr = temp;
                    count = 1;
                } else if (temp == maxOr) {
                    count++;
                }
            }
        }
        return count;
    }
};