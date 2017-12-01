//
// Created by Kristen Wong on 11/9/17.
//

#include <iostream>
#include <vector>
using namespace std;


class MergeKSortedListsSolution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        ListNode* merged = lists[0];
        if (lists.size() == 1) return merged;

        for (int i = 1; i < lists.size(); i ++) {
            merged = merge(merged, lists[i]);
        }
        return merged;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* merged, *head;
        if (list1->val < list2->val) {
            merged = list1;
            head = list1;
            list1 = list1->next;
        } else {
            merged = list2;
            head = list2;
            list2 = list2->next;
        }
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val){
                merged->next = list1;
                list1 = list1->next;
            } else {
                merged->next = list2;
                list2 = list2->next;
            }
        }

        if (list1 != NULL) {
            while (list1 != NULL){
                merged->next = list1;
                list1 = list1->next;
            }
        } else {
            while (list2 != NULL) {
                merged->next = list2;
                list2 = list2->next;
            }
        }
        return head;
    }
};