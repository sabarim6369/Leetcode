class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      return helper(nums,goal)-helper(nums,goal-1);
    }
    int helper(vector<int>&nums,int goal){
        int left=0;
        int count=0;
        int n=nums.size();
        long long currsum=0;
        for(int right=0;right<n;right++){
            if(goal<0)return 0;
            currsum+=nums[right];
            while(currsum>goal){
                   currsum-=nums[left];
                   left++;
            }
            count+=(right-left+1);

        }
        return count;
    }
};