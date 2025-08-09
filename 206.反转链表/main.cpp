#include <iostream>
using namespace std;

struct LinkNode {
    int val;
    LinkNode* next;
    LinkNode(int x): val(x), next(nullptr) {}
};

class MyLinkList {
public:
    LinkNode* dummy;
    int _size;

    MyLinkList() {
        dummy = new LinkNode(-1);
        _size = 0;
    }

    void create_MyLinkList() {
        LinkNode* cur = dummy;
        int x;
        while (cin >> x) {
            cur->next = new LinkNode(x);
            cur = cur->next;
            _size++;
        }
    }

    void printList() {
        LinkNode* cur = dummy->next;
        while (cur != nullptr) {
            cout << cur->val;
            if (cur->next != nullptr) cout << " -> ";
            cur = cur->next;
        }
        cout << endl;
    }

    // 迭代法
    void Reverse_LinkList_Iterative() {
        LinkNode* prev = nullptr;
        LinkNode* cur = dummy->next;
        LinkNode* next = nullptr;

        cout << "[迭代法] 初始链表: ";
        printList();

        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

            cout << "当前 prev 链: ";
            printFromNode(prev);
            cout << "剩余未处理链: ";
            printFromNode(cur);
            cout << "-----------------" << endl;
        }

        dummy->next = prev;
        cout << "[迭代法] 翻转完成链表: ";
        printList();
    }

    // 递归法封装
    void Reverse_LinkList_Recursive() {
        cout << "\n[递归法] 初始链表: ";
        printList();
        dummy->next = reverseRecursive(dummy->next);
        cout << "[递归法] 翻转完成链表: ";
        printList();
    }

private:
    void printFromNode(LinkNode* node) {
        if (!node) {
            cout << "null" << endl;
            return;
        }
        while (node != nullptr) {
            cout << node->val;
            if (node->next != nullptr) cout << " -> ";
            node = node->next;
        }
        cout << endl;
    }

    LinkNode* reverseRecursive(LinkNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // 递归出口
        }

        // 递归到链表尾部
        LinkNode* newHead = reverseRecursive(head->next);

        // 回溯阶段打印
        cout << "[回溯] 当前 head = " << head->val << "，执行翻转: "
             << head->next->val << " -> " << head->val << endl;

        // 翻转指针
        head->next->next = head;
        head->next = nullptr;

        // 打印当前 newHead 链表
        cout << "[回溯后链表] ";
        printFromNode(newHead);
        cout << "-----------------" << endl;

        return newHead;
    }
};

int main() {
    MyLinkList list;
    cout << "请输入链表元素（空格分隔，Ctrl+D 结束输入）: ";
    list.create_MyLinkList();

    list.Reverse_LinkList_Iterative();
    list.Reverse_LinkList_Recursive();

    return 0;
}
