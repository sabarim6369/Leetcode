class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int i=0,j=0;
        vector<int>finalarr;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                finalarr.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                finalarr.push_back(nums2[j]);
                j++;
            }
            else{
                finalarr.push_back(nums1[i]);
                i++;
            }
        }
         while (i < n1) finalarr.push_back(nums1[i++]);
        while (j < n2) finalarr.push_back(nums2[j++]);
        if(n%2!=0){
            return finalarr[n/2];

        }
        return (finalarr[n/2]+finalarr[(n/2)-1])/2.0;
       
    }
};