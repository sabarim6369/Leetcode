class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto a:arr){
            mp[a]++;
        }
        int missingcount=0;
        int num=1;
        while(true){
            if(mp.find(num)==mp.end()){
                missingcount++;
                 if(missingcount==k)return num;

            }
            num++;

        }
        return 0;
    }
};