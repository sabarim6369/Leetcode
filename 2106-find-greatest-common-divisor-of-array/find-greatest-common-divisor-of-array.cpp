class Solution {
public:
  
    int findGCD(vector<int>& nums) {
        int minele=*min_element(nums.begin(),nums.end());
        int maxele=*max_element(nums.begin(),nums.end());
        return gcd(minele,maxele);
    }
};