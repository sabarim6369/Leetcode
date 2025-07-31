class Solution {
public:
    set<int>ans;
    set<pair<int, int>> visited; 
    void helper(int index,int currxor,int size,vector<int>&arr){
        if(index==size)return;
        if(visited.count({index,currxor}))return;
        visited.insert({index,currxor});
        currxor|=arr[index];
        ans.insert(currxor);
        helper(index+1,currxor,size,arr);

    }
    int subarrayBitwiseORs(vector<int>& arr) {
       int n=arr.size();
       vector<int>dp;
       
        for(int i=0;i<n;i++){
           helper(i,0,n,arr);
           
        }
        return ans.size();
        
    }
};