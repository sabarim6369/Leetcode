class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     int prefixsum=0;
     int n=nums.size();
     int count=0;
     for(int i=0;i<n;i++){
      prefixsum+=nums[i];
      if(prefixsum==k){
        count++;
      }
      if(mp.find(prefixsum-k)!=mp.end()){
        count+=mp[prefixsum-k];
      }
      mp[prefixsum]++;

     }
     return count;
    
        
    }
   
};