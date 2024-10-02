#include<iostream>
using namespace std;
int reverse(int x) {
    int result = 0;
    bool isNegative = false;
    if (x == -pow(2, 31)) return 0;
    if (x < 0)
    {
        isNegative = true;
        x = -x;
    }
    while(x)
    {
        if (result > (pow(2, 31) - 1) / 10) return 0;
        result = result * 10 + x % 10;
        x /= 10;
    }
    return isNegative ? -result : result;
}
int main()
{
    int x;
    cin >> x;
    cout << reverse(x);
}

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside 
the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Dich: 
Cho một số nguyên x 32 bits có dấu, trả về x với các chữ số của nó được đảo ngược . Nếu đảo ngược x làm cho giá trị
nằm ngoài số nguyên 32 bits có dấu trong phạm vi [-2^31, 2^31 - 1], thì trả về 0  
Giả sử môi trường của bạn không cho phép bạn lưu trữ số nguyên 64 bits (có dấu hoặc không dấu)
Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-2^31 <= x <= 2^31 - 1
*/