class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>mp;
        int n=s.size();
        int count=0;
        int left=0;
        for(int right=0;right<n;right++){
           mp[s[right]]++;
        //    while(mp.size()==3){
        //     count++;
        //     count+=(n-(right+1));
        //     mp[s[left]]--;
        //     if(mp[s[left]]==0){
        //         mp.erase(s[left]);
        //     }
        //     left++;
        //    }
        while(mp['a']>0 && mp['b']>0 && mp['c']>0){
            count++;
            count+=(n-(right+1));
            mp[s[left]]--;
            left++;
        }


        }
return count;
    }
};