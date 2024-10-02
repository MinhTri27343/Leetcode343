#include<iostream>
using namespace std;
string longestPalindrome(string s)
{
    string result = "";
    result += s[0];
    for (int i = 1; i < s.size(); i++)
    {
        // Extend odd distance
        string oddDistance = "";
        oddDistance += s[i];
        int l = i - 1;
        int r = i + 1;
        while(l >= 0 && r < s.size())
        {
            if (s[l] == s[r])
            {
                oddDistance = s[l] + oddDistance;
                oddDistance += s[r];
            }
            else
            {
                break;
            }
            l--;
            r++;
        }
        // Extend even distance
        int prev = i - 1;
        int curr = i;
        string evenDistance = "";
        while(prev >= 0 && curr < s.size())
        {
            if (s[prev] == s[curr])
            {
                evenDistance = s[prev] + evenDistance;
                evenDistance += s[curr];
            }
            else break;
            prev--;
            curr++;
        }
        if (result.size() < oddDistance.size())
        {
            result = oddDistance;
        }
        if (result.size() < evenDistance.size())
        {
            result = evenDistance;
        }
    }
    return result;
}
int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}
/*
Problem: 
Given a string s, return the longest  palindromic substring in s.
Dich: 
Cho một chuỗi s, trả về chuỗi con đối xứng dài nhất trong s 
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/