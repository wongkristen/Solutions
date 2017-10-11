#include <iostream>
#include <vector>
#include "ref.h"

using namespace std;

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

int main(){
    // ------ Debug and test here ------

    LetterCombosofPhoneNumSolution lcpn;
    vector <string> ans = lcpn.letterCombinations("1234");

    for (int i = 0; i < ans.size(); i ++) cout << ans[i] << endl;

    ValidParenthesesSolution vp;
    cout << vp.isValid("((") << endl;

    MergeTwoListsSolution rnll;
    MergeTwoListsSolution::ListNode *ln = new MergeTwoListsSolution::ListNode(1);
    ln->next = new MergeTwoListsSolution::ListNode(3);
    MergeTwoListsSolution::ListNode *temp = ln->next;
    temp->next = new MergeTwoListsSolution::ListNode(4);
//    temp = temp->next;
//    temp->next = new MergeTwoListsSolution::ListNode(5);
//    temp = temp->next;
//    temp->next = new MergeTwoListsSolution::ListNode(9);



    MergeTwoListsSolution::ListNode *l2 = new MergeTwoListsSolution::ListNode(0);
//    l2->next = new MergeTwoListsSolution::ListNode(3);
//    temp = l2->next;
//    temp->next = new MergeTwoListsSolution::ListNode(5);
//    temp = temp->next;
//    temp->next = new MergeTwoListsSolution::ListNode(6);

    temp = rnll.mergeTwoLists(ln, l2);


    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    ThreeSumClosestSolution tsc;
    vector<int> intV;
    intV.push_back(0);
    intV.push_back(0);
    intV.push_back(0);
    intV.push_back(0);
    intV.push_back(0);

    cout << "three sum closest = " << tsc.threeSumClosest(intV, 12) << endl;
}
