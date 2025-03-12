class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int a[m + n];
        int len = max(m,n);
        int i = 1, j = 1, k = 1;
        while (i <= m && j <= n) {
            if (nums1[i] < nums2[j])
                a[k++] = nums1[i++];
            else
                a[k++] = nums2[j++];
        }
        if(m > n){
            while(i < m){
                a[k++] = nums1[i++];
            }
        } else {
            while(j < n){
                a[k++] = nums2[j++];
            }
        }
        if (k % 2 == 0)
            return (a[len / 2] + a[len / 2 - 1]) / 2.0;
        else
            return a[len / 2];
    }
};