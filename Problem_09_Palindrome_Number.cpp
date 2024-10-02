#include<iostream>
using namespace std;
bool isPalindrome(int x)
{
    if (x < 0) return false;
    int n = x;
    long long prev = 0;
    while(n)
    {
        prev = prev * 10 + n % 10;
        n /= 10;
    }
    return prev == x;
}
int main()
{
    int x;
    cin >> x;
    cout << isPalindrome(x);
}
/*
Problem
Given an integer x, return true if x is a palindrome, and false otherwise.
Dich: 
Bạn được đưa một số nguyên x, trả về true nếu x thì đối xứng và ngược lại trả về false
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
-2^31 <= x <= 2^31 - 1
*/