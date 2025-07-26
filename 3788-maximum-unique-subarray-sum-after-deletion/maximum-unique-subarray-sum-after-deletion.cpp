class Solution {
public:
    int maxSum(vector<int>& nums) {
       set<int>ans(nums.begin(),nums.end());
       if(ans.size()==1)return nums[0];
       int negcount=0;
       for(auto a:nums){
        if(a<0)negcount++;
       }
       if(negcount==nums.size()){
         return *max_element(nums.begin(), nums.end());
       }
       int currsum=0;
       for(auto a:ans){
        if(a<0)continue;
        currsum+=a;
       }
       return currsum;
    }
};