#include<iostream>
#include<string>
using namespace std;
 string convert(string s, int numRows) {
    string result = "";
    int n = numRows;
    if (numRows == 1)
    {
        result = s;
    }
    for (int i = 1; i <= n; i++)
    {
        int index = i - 1;
        if (index < s.size()) result.push_back(s[index]);
        while(index < s.size())
        {
            int temp1 = 2 * numRows - 2 * i;
            index += temp1;
            if (temp1 < s.size() && temp1 != 0 && index < s.size())
            {
                result += s[index];
            }
            int temp2 = 2 * i - 2;
            index += temp2;
            if (temp2 < s.size() && temp2 != 0 && index < s.size())
            {
                result += s[index];
            }
            if (temp1 == 0 && temp2 == 0) break;
        }
    }
    return result;
}
int main()
{
    string s;
    cin >> s;
    int numRows;
    cin >> numRows;
    string result = convert(s, numRows);
    cout << result;
    return 0;
}
/*
Problem: 
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display 
this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
Dich: 
Chuỗi "PAYPALISHIRING" thì được viết dưới mẫu zigzag với số hàng được cho sẵn: (Bạn có thể muốn hiển thị mẫu này với font
cố định để dễ đọc  hơn )
P   A   H   N
A P L S I I G
Y   I   R
và sau đó đọc theo từng hàng: "PAHNAPLSIIGYIR"
Viết đoạn code để mà nhận vào một chuỗi và làm chuyển đổi chuỗi này dựa trên số hàng đã cho 
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"
 

Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/

