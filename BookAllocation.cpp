class Solution {
public:
     bool ispossible(int mid,vector<int>&nums,int m){
        int currsum=0;
        int count=1;
        for(auto pages:nums){
            if(pages>mid)return false;
            if(currsum+pages>mid){
                count++;
                currsum=pages;
            }
            else{
                currsum+=pages;
            }


        }
        return count<=m;
     }
    int findPages(vector<int> &nums, int m)  {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        int minval=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            if(ispossible(mid,nums,m)){
                minval=mid;
                right=mid-1;
            }
            else{
                left=mid+1;

            }

        }
        return minval;
    }
};
