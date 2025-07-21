class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        
        long long maxele = *max_element(bloomDay.begin(), bloomDay.end());
        long long minele = *min_element(bloomDay.begin(), bloomDay.end());
        if ((long long)m * k > n) {
            return -1;
        }
        long long high = maxele;
        long long low = minele;
        long long minday=INT_MAX;
        while (low <= high) {
            long long mid = (low + high) / 2;
            bool ispossible = helper(mid, bloomDay, m, k,n);
            if(ispossible){
                minday=min(minday,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return minday;
    }
    bool helper(int mid, vector<int> bloomDay, int m, int k,int n) {
       long long count=0;
       long long bouquecount=0;
       for(int i=0;i<n;i++){
        if(bloomDay[i]<=mid){
            count++;
            if(count==k){
                bouquecount++;
                count=0;
            }
        }
        else{
            count=0;
        }
      
       }
       if(bouquecount>=m)return true;
       return false;
    }
};