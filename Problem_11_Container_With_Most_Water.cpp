#include<iostream>
#include<vector>
using namespace std;
 int maxArea(vector<int>& height)
{
    int maxContainer = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l <= r)
    {
        int container = (r - l) * min(height[l], height[r]);
        if (container > maxContainer)
        {
            maxContainer = container;
        }
        if (height[l] < height[r]) l++;
        else r--;
    }
    return maxContainer;
}
int main()
{
    int n;
    cin >> n;
    vector<int> height;
    while(n--)
    {
        int x;
        cin >> x;
        height.push_back(x);
    }
    cout << maxArea(height);
}

/*
Problem: 
Vertical: đứng 
Axis: trục
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the 
ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
Dich: 
- Bạn được cho một mảng các số nguyên "Height" với chiều dài n. Có n đường thẳng đứng được vẽ sao cho 2 điểm kết thúc của đường thẳng thứ i 
là (i, 0) và (i, height[i]).
Tìm 2 đường thẳng cùng với trục Ox tạo thành một thùng chứa sao cho thùng chứa chứa nhiều nước nhất.
Trả về lượng nước tối đa một thùng chứa có thể chứa.
Lưu ý bạn không thể nghiêng thùng chứa 
 
Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) 
the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
 
Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/