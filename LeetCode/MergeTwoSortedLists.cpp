//
// Created by Kristen Wong on 10/11/17.
//

#include <iostream>
using namespace std;

class MergeTwoListsSolution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // If either lists are empty, return the non empty list.
        if (l1 == nullptr || l2 == nullptr) return (l1 == nullptr) ? l2 : l1;

        ListNode *ans = NULL;

        if (l1->val < l2->val) {
            ans = l1;
            l1 = l1->next;
        }
        else {
            ans = l2;
            l2 = l2->next;
        }

        ListNode* temp = ans;
        while (l1 != nullptr && l2 != nullptr) {
            if (l2->val < l1->val) {
                cout << "here" << endl;
                temp->next = l2;
                l2 = l2->next;
            } else {
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
        }

        while (l1 != nullptr) {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
        delete(temp);
        delete(l1);
        delete(l2);

        return ans;
    }
};