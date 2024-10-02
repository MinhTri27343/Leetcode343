#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> arr;
    for (int i = 0; i < nums.size(); i++)
    {
        arr.clear();
        int temp = nums[i];
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {

        }
    }
}        
// -1,0,1,2,-1,-4
// -3 2 0 2 123123
int main()
{
    return 0;
}

/*
Problem: 
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Dich: 
Đưa một mảng số nguyên "nums", trả về tất cả bộ ba [nums[i], nums[j], nums[k]] sao cho 
i != j, i != k, và j != k, và nums[i] + nums[j] + nums[k] == 0.
Lưu ý tập hợp các giải pháp bắt buộc không chứa bộ ba trùng

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/