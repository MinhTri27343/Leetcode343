#include<iostream>
#include<vector>
using namespace std;
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merge;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            merge.push_back(nums1[i]);
            i++;
        }
        else 
        {
            merge.push_back(nums2[j]);
            j++;
        }
    }
    while(i < nums1.size())
    {
        merge.push_back(nums1[i]);
        i++;
    }
    while(j < nums2.size())
    {
        merge.push_back(nums2[j]);
        j++;
    }
    double result = 0;
    if (merge.size() % 2 == 1)
    {
        result =  merge[merge.size() / 2];
    }
    else
    {
        int index1 = merge.size() / 2 - 1;
        int index2 = merge.size() / 2;
        result = (1.0 * (merge[index1] + merge[index2])) / 2;
    }
    return result;
}
int main()
{

}

/*
Problem: 
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Dich: 
Được đưa vào 2 mảng đã được sắp xếp nums1 và nums2 với kích thước m và n tương ứng, trả về trung vị của 2 mảng được sắp xếp.
Độ phức tạp thời gian chung nên là O(log(m + n))
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/