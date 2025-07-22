class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int left=0;
        int n=nums.size();
        int maxsum=0;
        int currsum=0;
        for(int right=0;right<n;right++){
            mp[nums[right]]++;
            currsum+=nums[right];
            while(mp.size()<right-left+1){
                mp[nums[left]]--;
               currsum-=nums[left];
               if(mp[nums[left]]==0){
                mp.erase(nums[left]);
               }
                left++;
            }
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};