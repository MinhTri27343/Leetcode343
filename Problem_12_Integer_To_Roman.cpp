#include<iostream>
#include<math.h>
using namespace std;
char convert(int s)
{
    if (s == 1) return 'I';
    else if (s == 5) return 'V';
    else if (s == 10) return 'X';
    else if (s == 50) return 'L';
    else if (s == 100) return 'C';
    else if (s == 500) return 'D';
    else if (s == 1000) return 'M';
    return 0;
}
int countDigits(int num)
{
    int count = 0;
    while(num)
    {
        count++;
        num /= 10;
    }
    return count;
}
int reverseNumber(int num)
{
    int reverse = 0;
    while (num)
    {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return reverse;
}
string intToRoman(int num) {
    string result;
    int temp1[] = {1, 10, 100, 1000};
    int temp2[] = {5, 50, 500};
    while(num)
    {
        int numberDigits = countDigits(num);
        int temp = pow(10, numberDigits - 1);
        int analysis = 0;
        if (numberDigits >= 2)
        {
            analysis = num -num % temp;
            num = num - analysis;
        }
        else
        {
            analysis = num;
            num = 0;
        }
        int reverse = reverseNumber(analysis);
        if (reverse == 4)
        {
            result += convert(temp1[numberDigits - 1]);
            result += convert(temp2[numberDigits - 1]);
        }
        else if (reverse == 9)
        {
            result += convert(temp1[numberDigits - 1]);
            result += convert(temp1[numberDigits]);
        }
        if (reverse >= 5 && reverse <= 8)
        {
            result += convert(temp2[numberDigits - 1]);
            reverse -= 5;
        }
        if (reverse >= 1 && reverse <= 3)
        {
            while (reverse--)
            {
                result += convert(temp1[numberDigits - 1]);
            }
        }

    }  
    return result;
}
int main()
{    
    int n;
    cin >> n;
    cout << intToRoman(n);
}
/*
Problem: 
Seven different symbols represent Roman numerals with the following values:
Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. 
Converting a decimal place value into a Roman numeral has the following rules:
If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input,
 append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol,
 for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 
 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L),
 or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

Dich: 
7 kí tự khác nhau đươc biểu diễn số la mã với giá trị sau: 
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Số la mã được tạo thành bằng cách chèn vào cuối, chuyển đổi các giá trị thập phân từ cao nhất đến thấp nhất
Chuyển đổi giá trị thập phân thành số la mã tuân theo quy tắc sau:
Nếu giá trị không bắt đầu với 4, 9, chọn ký hiệu của giá trị lớn mà nó có thể trừ từ input
chèn vào cuối các kí tự đó từ kết quả, trừ đi giá trị của nó, và chuyển đổi phần còn lại của số la mã.

Nếu giá trị bắt đầu với 4 hoặc 9 thì sử dụng phép trừ để tạo thành một kí tự bị trừ từ kí tự kế tiếp,
ví dụ 4 thì là 1 (I) nhỏ hơn 5(V); IV và 9 là 1(I) nhỏ hơn 10 (X): IX. Chỉ dạng trừ sau được sử dụng 
Chỉ các bội của 10 (I, X, C, M) có thể được nối liên tiếp tối đa 3 lần để biểu diễn bội số của 10. Bạn không thể nối 
vào cuối 5 (V), 50 (L), hoặc 500(D) nhiều lầ. Nếu bạn cần chèn kí hiệu 4 lần thì sử dụng biểu mẫu trừ
Đưa bạn một số nguyên, chuyển đổi nó thành số la mã
Example 1:
Input: num = 3749
Output: "MMMDCCXLIX"
Explanation:
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

Example 2:
Input: num = 58
Output: "LVIII"
Explanation:
50 = L
8 = VIII

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation:
1000 = M
 900 = CM
  90 = XC
   4 = IV
 
Constraints:
1 <= num <= 3999
*/