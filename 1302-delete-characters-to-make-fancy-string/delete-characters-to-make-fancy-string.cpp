class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string ans="";
        unordered_map<char,int>mp;
       for(int i=0;i<n;i++){
        mp[s[i]]++;
        if(mp[s[i]]>=3 && s[i-1]==s[i] && s[i-2]==s[i]){
            continue;
        }
        else{
            ans+=s[i];
        }
       }
return ans;
    }
};