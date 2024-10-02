#include<iostream>
#include<vector>
using namespace std;
int sizeMin(vector<string> strs)
{
    int minSize = 1e9;
    for (string x: strs)
    {
        if (x.size() < minSize)
        {
            minSize = x.size();
        }
    }
    return minSize;
}
 string longestCommonPrefix(vector<string>& strs) {
    int f[1000] = { 0 };
    int n = sizeMin(strs);
    string result = "";
    for (int i = 0; i < n; i++)
    {
        char compare = strs[0][i];
        bool oke = true;
        for (string x: strs)
        {
            if (x[i] != compare)
            {
                oke = false;
                break;
            }
        }
        if (oke)
        {
            result += compare;
        }
        if (!oke) break;
    }
    return result;
 }

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Dich: 
Viết hàm để tìm chuỗi tiền tố chung lớn nhất trong số mảng các chuỗi kí tự.
Nếu không có tiền tố chung, trả về một chuỗi trống
 
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/