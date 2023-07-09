#include <iostream>

using namespace std;

struct LinkList {
    LinkList(int v):value(v){}
    int value;
    LinkList *next = NULL;
};

class Solution
{
public:
    LinkList * reserver(LinkList *&head, int k, LinkList *&s_next) {
        //上一个节点
        LinkList *pre = NULL;
        //要翻转的当前节点
        LinkList *cur = head;
        //下一个节点
        LinkList *next = NULL;

        //逐一翻转
        while(cur && k--) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        //新链表的最后一个节点
        LinkList *end = head;

        //新的子链表头
        head = pre;

        //未翻转的节点
        s_next = cur;

        if (k != -1) {
            //不满足k的长度，把翻转过来的子链表再翻转回去
            //TODO 翻转链表
            s_next = NULL;
        }

        return end;
    }
    LinkList * reserverGroup(LinkList *&head, int k) {
        //翻转的起始节点
        LinkList *start = head -> next;
        head ->next = NULL;
        //翻转后的尾节点
        LinkList *end = NULL;
        //保存上一次的尾节点
        LinkList *pre_end = NULL;
        //尾节点的下一个节点
        LinkList *next = NULL;

        while(true) {
            //start是翻转的起始节点，k是翻转的长度，next翻转后的end的下一个节点
            end = reserver(start, k, next);
            //当head->next为NULL时，执行第一次翻转的指针为头节点
            if (!head->next) {
                head->next = start;
            }


            //当放回的next节点为空时，表示没有翻转到链表尾部了，这是跳出循环
            if (!next) {
                //把翻转过的子链表再翻转回来
                reserver(start, k, next);
                if (pre_end) {
                    pre_end->next = start;
                }
                break;
            }
            //上一次的尾节点next执行这次翻转的头节点
            if (pre_end) {
                pre_end->next = start;
            }
            pre_end = end;
            start = next;
        }
        return head;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    LinkList *head = new LinkList(0);
    int i = 0;
    LinkList *node = head;
    while(i++ < 5) {
        LinkList *newNode = new LinkList(i);
        node->next = newNode;
        node = newNode;
    }
    Solution solu;
    head = solu.reserverGroup(head, 2);
    return 0;
}