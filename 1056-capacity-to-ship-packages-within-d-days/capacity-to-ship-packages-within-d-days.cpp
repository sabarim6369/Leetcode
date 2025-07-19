class Solution {
public:
    bool ispossible(int days, vector<int> weights, int mid, int n, int sum) {
        int currdays = 1;  //because we were started loading.That is day1.So ithayum count karo
        int currsum = 0;
        for (int i = 0; i < n; i++) {
            currsum += weights[i];
            if (currsum > mid) {
                currsum = weights[i];
                currdays++;
            }
        }
        return currdays<=days?true:false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = sum;
        int minans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ispossible(days, weights, mid, n, sum)) {
                high = mid - 1;
                minans = mid;
            } else {
                low = mid + 1;
            }
        }
        return minans;
    }
};