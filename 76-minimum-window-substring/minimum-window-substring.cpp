class Solution {
public:
    bool isvalid(unordered_map<char, int>& smap,
                 unordered_map<char, int>& tmap) {
        for (auto [val, count] : tmap) {
            if (smap[val] < count) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int tsize = t.size();
        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;

        for (auto a : t) {
            tmap[a]++;
        }
        int left = 0;
        int minlength = INT_MAX;
        string dummy = "";
        int startindex=0;
        for (int right = 0; right < n; right++) {
            smap[s[right]]++;
            while (isvalid(smap, tmap)) {
                if (right - left + 1 < minlength) {
                    minlength = right-left+1;
                    startindex=left;
                  
                }
                smap[s[left]]--;
                left++;
            }
        }

       cout<<minlength;
       return minlength==INT_MAX?"":s.substr(startindex,minlength);
    }
};