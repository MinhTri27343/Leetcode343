#include<iostream>
using namespace std;
int convert(char s)
{
    if (s == 'I') return 1;
    else if (s == 'V') return 5;
    else if (s == 'X') return 10;
    else if (s == 'L') return 50;
    else if (s == 'C') return 100;
    else if (s == 'D') return 500;
    else if (s == 'M') return 1000;
    return 0;
}
 int romanToInt (string s) {
    s += 'A';
    int result = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        int curr = convert(s[i]);
        int next = convert(s[i + 1]);
        if (curr >= next)
        {
            result += curr;
        }
        else 
        {
            result -= curr; 
        }
    }
    return result;
 }
int main()
{
    string s;
    cin >> s;
    cout << romanToInt(s);
    return 0;
}

/*
Problem:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine,
 which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
Dich: 
- Số la mã thì được biểu diễn bởi 7 kí hiệu khác nhau: I, V, X, L, C, D và M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
- Ví dụ, 2 thì được viết bởi II trong số la mã, chỉ 2 số 1 được cộng lại với nhau. 12 thì được viết là XII, nó đơn giản là X + II.
Số 27 được viết là XXVII, nó là XX + V + II
Số la mã thì thường được viết từ lớn nhất đến nhỏ nhất từ trái sang phải. Tuy nhiên, số  4 thì không là IIII.
Thay vào đó, số 4 thì được viểt là IV. Bởi vì 1 thì đứng trước 5 nên chúng ta trừ nó thành 4. Nguyên tắc như vậy áp dụng đối với số 9, nó được viết là
IX. Có 6 trường hợp mà phép trừ được sử dụng: 
I có thể đứng trước V (5) và X (10) thành 4 và 9. 
X có thể đứng trước L (50) và C (100) thành 40 và 90. 
C có thể đứng trước D (500) và M (1000) thành 400 và 900. 
Bạn được cho một số la mã, chuyển đổi nó thành số nguyên

 

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/