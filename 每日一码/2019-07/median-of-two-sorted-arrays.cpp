/*
@ NO: 4
@ Hard
 */

//Description: find two sorted array's median
#include "../INCLUDE/GLOBAL.H"

double getKminest(deque<int>& nums1, deque<int>& nums2, int k){
        int m = nums1.size(), n = nums2.size();
        if(m > n){
           return getKminest(nums2, nums1, k);
        }
        if(m == 0){
           return nums2[k-1];
        }
        if(k == 1){
           return min(nums1[0], nums2[0]);
        }

        int index1 = min(k/2, m) - 1, index2 = k - index1 - 1 - 1;
        if(nums1[index1] < nums2[index2]){
           int x = 0;
           while(x++ < index1 + 1){
              nums1.pop_front();
           }
           return getKminest(nums1, nums2, k - index1 - 1);
        }else if(nums1[index1] > nums2[index2]){
           int y = 0;
           while (y++ < index2 + 1)
           {
              nums2.pop_front();
           }
           return getKminest(nums1, nums2, k - index2 - 1);
        }else
        {
           return nums1[index1];
        }
        
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        bool isEven = (len1 + len2) % 2 == 0 ? true : false;
        double ans = 0.0;
        deque<int> dq1;
        deque<int> dq2;
        for(auto it : nums1){
           dq1.push_back(it);
        }
        for(auto it : nums2){
           dq2.push_back(it);
        }
        if(isEven){
           deque<int> dq3(dq1);
           deque<int> dq4(dq2);
           double m1 = getKminest(dq1, dq2, (len1 + len2) / 2);
           double m2 = getKminest(dq3, dq4, (len1+len2) / 2 + 1);
           ans = (m1 + m2) / 2.0;
        }else{
           ans = getKminest(dq1, dq2, (len1 + len2) / 2  + 1 );
        }
        return ans;
}





// Solve details
/*
   用解决求第k小数的思路来解决这个问题。
   求整个序列的中位数，相当于此时 k = (size1 + size2) / 2 - 1 #此时序列的长度为奇数，偶数时要求两次，然后取平均
   具体来说，假设有这样的两个有序数组 A,B,长度分别为 m和n
   在连个数组中求 第 k/2 小的数，A[index1],B[index2]，对于这两个边界值，若A中的较小，则将A中小的那一半丢弃，然后再次递归
   同样，若B中的较小，则丢弃B中小的那一半，然后继续下一步递归
   直到 A和B中 中值相等或k=1 终止递归

   也可以考虑  比较连个待合并数组的中值附近的四个值得大小关系来求解
 */