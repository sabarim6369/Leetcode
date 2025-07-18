class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int n=nums.size();
       int prefixsum=nums[0];
       unordered_map<int,int>mp;
       int count=0;
       mp[nums[0]%k]=0;
      for(int i=1;i<n;i++){
        prefixsum+=nums[i];
        int mod=prefixsum%k;
        if(prefixsum%k==0)return true;
        if(mp.find(mod)!=mp.end()){
            if(i-mp[mod]>=2){
                return true;
            }
        }
        else{        mp[mod]=i;
}

      }
      return false;
    }
};