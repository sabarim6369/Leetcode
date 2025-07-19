class Solution {
public:
    long long helper(int mid, vector<int>& piles, int n) {
        long long count = 0;
        for (int i = 0; i < n; i++) {
            count += ceil((double)piles[i] / mid);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        long long minans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long hours = helper(mid, piles, n);

            if (hours <= h) {
                minans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minans;
    }
};