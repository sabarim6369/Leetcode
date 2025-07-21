class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int minin=INT_MAX;
        int maxindex=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                minin=min(i,minin);
                maxindex=max(maxindex,i);
            }
        }
        return {minin==INT_MAX?-1:minin,maxindex==INT_MIN?-1:maxindex};
    }
};