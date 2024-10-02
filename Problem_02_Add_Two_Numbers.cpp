#include<iostream>
#include<string>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 string getInteger(ListNode* l)
 {
    string s = "";
    while(l)
    {
        s += to_string(l->val);
        l = l->next;
    }
    return s;
 }
 string addTwoString(string a, string b)
 {
    if (a.size() < b.size())
    {
        a.insert(a.size(), b.size() - a.size(), '0');
    }
    else if (a.size() > b.size())
    {
        b.insert(b.size(), a.size() - b.size(), '0');
    }
    cout << a << " " << b << endl;
    int index = 0;
    string result = "";
    int du = 0;
    while(index < a.size() && index < b.size())
    {
        int temp = a[index] - '0' + b[index] - '0' + du;
        if (temp >= 10)
        {
            du = 1;
            temp -= 10;
        }
        else
        {
            du = 0;
        }
        index++;
        result += to_string(temp);
    }
    if (du == 1)
    {
        result += to_string('1');
    }
    reverse(result.begin(), result.end());
    return result;
 }
 ListNode* createNode(long long data)
 {
    ListNode* create = new ListNode;
    create->next = NULL;
    create->val = data;
    return create;
 }
 void addTail(ListNode*& L, long long val)
 {
    ListNode* create = createNode(val);
    if (L == NULL)
    {
        L = create;
        return;
    }
    ListNode* curr = L;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = create;
    return;

 }
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = NULL;
    string number1 = getInteger(l1);
    string number2 = getInteger(l2);
    string kq = addTwoString(number1, number2);
    for (int i = kq.size() - 1; i >= 0; i--)
    {
        addTail(result, kq[i] - '0');
    }
    return result;
}
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Dich: 
Bạn được đưa 2 danh sách liên kết không rỗng biểu diễn bởi 2 số nguyên không âm. Các chữ số được lưu trữ theo thứ tự ngược,
và mỗi node của nó chứa duy nhất một chữ số. Cộng 2 số và trả về tổng như là một danh sách liên kết.
Bạn có thể giả sử 2 số nguyên không chứa bất kì số 0 đứng đầu nào, ngoại trừ số 0 chính nó 
*/