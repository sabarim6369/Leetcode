class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m=baskets.size();
        vector<bool> check(m,true);
        int placed=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check[j]){
                    if(baskets[j]>=fruits[i]){
                        check[j]=false;
                        placed++;
                        break;
                    }
                

                }

            }
        }
        return n-placed;
       
    }
};