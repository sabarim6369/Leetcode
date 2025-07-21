class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mp;
        int n=s.size();
        int maxwindow=0;
        int maxele=0;
        int left=0;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            int currlength=right-left+1;
            maxele=max(maxele,mp[s[right]]);
            int rem=currlength-maxele;
            if(rem<=k){
                maxwindow=max(maxwindow,currlength);
            }
            while(rem>k){
                mp[s[left]]--;
                left++;
                int dummycurrlength=right-left+1;
                rem=dummycurrlength-maxele;
            }
        }
        return maxwindow;
    }
};