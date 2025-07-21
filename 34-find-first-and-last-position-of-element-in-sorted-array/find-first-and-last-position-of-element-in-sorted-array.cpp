class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      auto first=lower_bound(nums.begin(),nums.end(),target);
      auto second=upper_bound(nums.begin(),nums.end(),target);
      if(first==nums.end() || *first!=target){
        return {-1,-1};
      }
      int start=first-nums.begin();
      int end=second-nums.begin()-1;
      return {start,end};
      
      return {};
    }
};