class Solution {
public:
    bool ispossible(int mid,vector<int>&nums,int k){
        int count=1;
        int currsum=0;
        for(auto a:nums){
            if(a>mid)return false;
            if(currsum+a>mid){
                currsum=a;
                count++;
                if(count>k)return false;
            }
            else{
                currsum+=a;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        int minans=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            if(ispossible(mid,nums,k)){
                minans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            
        }
        return minans;
    }
};