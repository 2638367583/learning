#include <iostream>
#include <vector>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (head->next == NULL) {
            return vector<int>();
        }
        ListNode *node = head->next;
        vector<int> vec = reversePrint(node);
        vec.push_back(node->val);
        cout << node->val << endl;
        return vec;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    ListNode *head = new ListNode(1);
    ListNode *node = head;
    for (int i = 0; i < 5; i++) {
        ListNode *value = new ListNode(i);
        node->next = value;
        node = node->next;
    }

    node = head;
    while(node->next != NULL) {
        node = node->next;
        cout << node->val << endl;
    }


    Solution solu;
    vector<int> vec = solu.reversePrint(head);
    for (auto num : vec) {
        cout << num << endl;
    }

    return 0;
}