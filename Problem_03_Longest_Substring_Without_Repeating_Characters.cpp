#include<iostream>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    if (s == "") return 0;
    int mark[300] = { 0 };
    int l = 0;
    int r = 1;
    int maxLength = 1;
    mark[s[l]] = 1;
    while (r < s.size())
    {
        if (mark[s[r]] == 1)
        {
            while(mark[s[r]] == 1)
            {
                mark[s[l]] = 0;
                l++;
            }
        }
        int dis = r - l + 1;
        if (dis > maxLength) 
        {
            maxLength = dis;
        }
        mark[s[r]] = 1;   
        r++;
    }
    return maxLength;
}
int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
}
/*
Problem: 
Given a string s, find the length of the longest 
substring without repeating characters.
Dich:
Bạn đưa đưa mỗi chuỗi s, tìm chiều dài lớn nhất của chuỗi con
mà không có kí tự lặp lại

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/