#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
 #define MAX_INT32 2147483648

bool isGreater(string a, string b)
{
    if (a.size() > b.size()) return true;
    else if (a.size() < b.size()) return false;
    else return a > b;
}
int myAtoi(string s) {
    string result = "";
    int number = 0;
    int indexStart = 0;
    while(indexStart < s.size() && s[indexStart] == ' ')
    {
        indexStart++;
    }
    bool isNegative = false;
    if (indexStart < s.size())
    {
        if (s[indexStart] == '-') 
        {
            indexStart++;
            isNegative = true;
        }
        else if (s[indexStart] == '+')
        {
            indexStart++;
            isNegative = false;
        }
    }
    while(indexStart < s.size() && s[indexStart] == '0')
    {
        indexStart++;
    }
    for (int i = indexStart; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            result += s[i];
        }
        else
        {
            break;
        }
    }
    if (result == "") return 0;
    if (isNegative)
    {
         string minInt = to_string(MAX_INT32);
        if (isGreater(result, minInt))
        {
            number = -MAX_INT32;
        }
        else{
            number = stoi('-' + result);
        }
    }
    else
    {
        int a = MAX_INT32 - 1;
        string maxInt = to_string(a);
        if (isGreater(result, maxInt))
        {
            number = a;
        }
        else{
            number = stoi(result);
        }
    } 
    return number;
}
int main()
{
    string s;
    cin >> s;
    cout << myAtoi(s);
}

/*
Problem: 
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. 
If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. 
Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
Return the integer as the final result.
Dich: 
Thực hiện hàm myAtoi(string s), để mà chuyển đổi chuỗi thành số nguyên có dấu 32-bit
Thuật toán cho myAtoi(string s) thì như sau: 
Khoảng trắng: Loại bỏ tất cả khoảng trắng ở đầu
Dấu: Xác định dấu bằng việc kiểm tra kí tự kế tiếp là '-' hay '+', giả sử số nguyên thì không cần biểu diễn
Chuyển đổi: Đọc số nguyên bằng việc bỏ qua số 0 ở đầu cho đến khi  kí tự không phải là chữ sô thì được bắt gặp  hoặc khi đạt được kết thúc của chuỗi.
Nếu không có chữ số nào được đọc, thì kết quả là 0
Làm tròn: Nếu số nguyên thì nằm ngoài phạm vi số nguyên có dấu 32-bit [-2^31, 2^31 - 1], thì làm tròn số nguyên vẫn duy trì trong phạm vi. 
Cụ thể, số nguyên nhỏ hơn -2^31 thì sẽ được làm tròn thành -2^31, và số nguyên lớn hơn 2^31 -1 thì sẽ được làm tròn thành 2^31 - 1.
Trả về số nguyên như là kết quả cuối cùng

Example 1:
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
Step 2: "42" (no characters read because there is neither a '-' nor '+')
Step 3: "42" ("42" is read in)

Example 2:
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
Step 2: "   -042" ('-' is read, so the result should be negative)
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)

Example 3:
Input: s = "1337c0d3"
Output: 1337
Explanation:
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)

Example 4:
Input: s = "0-1"
Output: 0
Explanation:
Step 1: "0-1" (no characters read because there is no leading whitespace)
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)

Example 5:
Input: s = "words and 987"
Output: 0
Explanation:
Reading stops at the first non-digit character 'w'.

Constraints:
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/