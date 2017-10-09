//
// Created by Kristen Wong on 10/9/17.
//

#include <stack>
using namespace std;

// Given a singly linked list, determine if it is a palindrome.

class IsPalindromeLinkedListSolution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    bool isPalindrome(ListNode* head) {
        if(head == nullptr) {return true;}

        ListNode *temp = head;
        stack <int> s;
        s.push(temp -> val);

        while (temp -> next != nullptr){
            temp = temp -> next;
            s.push(temp -> val);
        }

        temp = head;
        while (temp -> next != nullptr){
            if(s.top() != temp -> val) {return false;}

            s.pop();
            temp = temp -> next;
        }

        return true;
    }
};