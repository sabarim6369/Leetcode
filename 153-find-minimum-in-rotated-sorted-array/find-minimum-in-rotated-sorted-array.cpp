class Solution {
public:
    int findMin(vector<int>& arr) {
        // return *min_element(nums.begin(),nums.end());
        int low=0;
        int high=arr.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(arr[mid]>arr[high]){
                low=mid+1;
            }
            else if(arr[mid]<arr[high]){
                high=mid;
            }
         
        }
        return arr[low];
    }
};