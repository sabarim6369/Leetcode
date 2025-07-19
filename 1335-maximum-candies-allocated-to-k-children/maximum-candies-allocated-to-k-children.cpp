class Solution {
public:
   bool ispossible(long long mid,vector<int>&candies,int n,int k){
   long long count=0;
   for(int i=0;i<n;i++){
    count+=candies[i]/mid;
   }
   return count>=k?true:false;


   }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=accumulate(candies.begin(),candies.end(),0LL);
        if(k>sum)return 0;
        int n=candies.size();
        long long low=1;
        long long high=sum/k;
        long long maxans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(ispossible(mid,candies,n,k)){
                maxans=max(maxans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return (int)maxans;
    }
};