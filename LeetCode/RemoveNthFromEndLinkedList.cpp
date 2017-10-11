//
// Created by Kristen Wong on 10/10/17.
//


#include <iostream>
using namespace std;

// Solution achieved in one pass using two pointers.

class RemoveNthFromEndLinkedListSolution {

public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr; // For case: list size = 1, n = 1

        ListNode *second = head;

        for (int i = 0; i < n; i ++) second = second->next;

        if (second == nullptr) {
            head = head->next;
            return head;
        }

        ListNode *first = head;
        while (second->next  != nullptr) {
            first = first->next;
            second = second->next;
        }
        if(n == 1){
            first->next = nullptr;
            return head;
        }
        second = first->next->next;
        first->next->next = nullptr;
        first->next = second;


        return head;
    }
};