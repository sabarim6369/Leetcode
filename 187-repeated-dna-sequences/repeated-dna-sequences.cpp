class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string>st;
        set<string>result;
        int n=s.size();
        if(n<10){
            return {};
        }
        for(int i=0;i<=n-10;i++){
            string dummy=s.substr(i,10);
            if(st.find(dummy)!=st.end()){
                result.insert(dummy);
            }
            else{
                st.insert(dummy);
            }
        }
        return vector<string>(result.begin(),result.end());
    }
};