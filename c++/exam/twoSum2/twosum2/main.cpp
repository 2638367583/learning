#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
 using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     explicit ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr) {
            std:cout << "The paramter l1 or l2 is nullptr.";
            return nullptr;
        }
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *q = nullptr;
        ListNode *head = nullptr;
        bool isCarry = false;
        while(p1 != nullptr || p2 != nullptr) {
            int sum = 0;
            if (p1 != nullptr) {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                sum += p2->val;
                p2 = p2->next;
            }

            sum += isCarry;
            if (sum >= 10) {
                isCarry = true;
            } else {
                isCarry = false;
            }

            auto *node = new ListNode(sum % 10);
            node ->next = nullptr;
            if (q == nullptr) {
                q = node;
                head = node;
            } else {
                q ->next = node;
                q = node;
            }

        }
        if (isCarry) {
            auto *node = new ListNode(isCarry);
            node ->next = nullptr;
            if (q) {
                q ->next = node;
                q = node;
            }
        }
        return head;
    }

public:
     void printString(const ListNode *list) {
        const ListNode *p = list;
        while (p != nullptr) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};

void test1() {
    Solution solu;
    ListNode *l = nullptr;
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(4);
    l1->next = l2;
    ListNode *l3 = new ListNode(3);
    l2->next = l3;
    l3->next = nullptr;
    l=l1;
    solu.printString(l);
    ListNode *la = nullptr;
    ListNode *lb = new ListNode(2);
    ListNode *lc = new ListNode(6);
    lb->next = lc;
    ListNode *ld = new ListNode(3);
    lc->next = ld;
    ld->next = nullptr;
    la=lb;
    solu.printString(la);
    solu.printString(solu.addTwoNumbers(l, la));

}
void test2() {
    Solution solu;
    ListNode *l = nullptr;
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(4);
    l1->next = l2;
    l2->next = nullptr;
    l=l1;
    solu.printString(l);
    ListNode *la = nullptr;
    ListNode *lb = new ListNode(2);
    ListNode *lc = new ListNode(6);
    lb->next = lc;
    lc->next = nullptr;
    la=lb;
    solu.printString(la);
    solu.printString(solu.addTwoNumbers(l, la));
}
int main() {
    std::cout << "test one:" << std::endl;
    test1();
    std::cout << "test two:" << std::endl;
    test2();
    return 0;
}

