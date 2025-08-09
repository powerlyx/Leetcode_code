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

    // ������
    void Reverse_LinkList_Iterative() {
        LinkNode* prev = nullptr;
        LinkNode* cur = dummy->next;
        LinkNode* next = nullptr;

        cout << "[������] ��ʼ����: ";
        printList();

        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

            cout << "��ǰ prev ��: ";
            printFromNode(prev);
            cout << "ʣ��δ������: ";
            printFromNode(cur);
            cout << "-----------------" << endl;
        }

        dummy->next = prev;
        cout << "[������] ��ת�������: ";
        printList();
    }

    // �ݹ鷨��װ
    void Reverse_LinkList_Recursive() {
        cout << "\n[�ݹ鷨] ��ʼ����: ";
        printList();
        dummy->next = reverseRecursive(dummy->next);
        cout << "[�ݹ鷨] ��ת�������: ";
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
            return head; // �ݹ����
        }

        // �ݹ鵽����β��
        LinkNode* newHead = reverseRecursive(head->next);

        // ���ݽ׶δ�ӡ
        cout << "[����] ��ǰ head = " << head->val << "��ִ�з�ת: "
             << head->next->val << " -> " << head->val << endl;

        // ��תָ��
        head->next->next = head;
        head->next = nullptr;

        // ��ӡ��ǰ newHead ����
        cout << "[���ݺ�����] ";
        printFromNode(newHead);
        cout << "-----------------" << endl;

        return newHead;
    }
};

int main() {
    MyLinkList list;
    cout << "����������Ԫ�أ��ո�ָ���Ctrl+D �������룩: ";
    list.create_MyLinkList();

    list.Reverse_LinkList_Iterative();
    list.Reverse_LinkList_Recursive();

    return 0;
}
