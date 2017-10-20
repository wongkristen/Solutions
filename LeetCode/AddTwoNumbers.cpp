//
// Created by Kristen Wong on 10/18/17.
//

#include <iostream>
using namespace std;

// Time complexity: O(n) - where n = the length of the longer list.
// Space complexity O(n) - the max length of the new list is at most n + 1

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = 0;
        ListNode* temp = nullptr;
        ListNode* ans = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;

            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else carry = 0;

            ListNode* node = new ListNode(sum);
            if(temp == nullptr) {
                temp = node;
                ans = node;
            }
            else {
                temp->next = node;
                temp = node;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            int sum = l1->val + carry;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else carry = 0;

            ListNode* node = new ListNode(sum);
            temp->next = node;
            temp = node;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            int sum = l2->val + carry;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else carry = 0;

            ListNode* node = new ListNode(sum);
            temp->next = node;
            temp = node;
            l2 = l2->next;
        }

        if (carry == 1) {
            ListNode* node = new ListNode(1);
            temp->next = node;
        }
        return ans;
    }
};