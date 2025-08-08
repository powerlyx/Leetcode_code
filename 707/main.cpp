#include <iostream>

using namespace std;

struct LinkNode {
    int val;
    struct LinkNode* next;
    LinkNode(int x): val(x), next(nullptr){}
};

class MyLinkList{
public:
    struct LinkNode* dummy;
    int _size;

    MyLinkList(){
        dummy = new LinkNode(-1);
        _size = 0;
    }

    // ��������
    void create_MyLinkList(){
         struct LinkNode* cur =  dummy;
         int x;

         while(cin >> x ){
           cur->next= new LinkNode(x);
            cur = cur->next;
            _size++; // ά������
         }
    }

    void printList(){
          struct LinkNode* cur =  dummy->next;
          while( cur!= nullptr){
            cout << cur->val;
            if (cur->next != nullptr) cout<< "->";
            cur = cur->next;
          }
             cout << " -> NULL" << endl;
    }
    int get(int index){
         struct LinkNode* cur =  dummy->next;
        if( index <0 || index >= _size) return -1;

        for( int i=0; i<index;i++){
                cur= cur->next;
        }
        return cur->val;
    };

    void addAtHead(int val){
        struct LinkNode* cur = new LinkNode(-1);
        cur->val= val;
        cur->next = dummy->next;
        dummy->next = cur;
        _size++;
    };

    void addAtTail(int val){
         struct LinkNode* cur =  dummy->next;
         while(cur->next !=nullptr){
            cur = cur->next;
         }
         struct LinkNode* p = new LinkNode(val);
         p->next= cur->next;
         cur->next = p;
         _size++;
    }

    void addAtIndex(int val, int index){
        if (index <0) index = 0;
        if (index >_size) return;

        LinkNode* cur = dummy;
        for(int i=0; i<index;i++){
            cur = cur->next;
        }
        LinkNode* p = new LinkNode(val);
        p->next = cur->next;
        cur->next = p;
        _size++;
    }
     void DeleteAtIndex(int index){
        if(index < 0 || index >=_size) return;

        LinkNode* cur = dummy;
           for(int i=0; i<index;i++){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        _size--;
     }
};


int main()
{
    MyLinkList list;
    cout << "��ʼ����" << endl;
    list.printList(); // ������

    //���Դ�������
    cout << "����������ڵ�ֵ���ÿո������Ctrl+D ������:" << endl;
    list.create_MyLinkList();
    list.printList(); // �����������

    // ���� addAtHead
    list.addAtHead(1);
    cout << "addAtHead(1) ��" << endl;
    list.printList();

    // ���� addAtTail
    list.addAtTail(3);
    cout << "addAtTail(3) ��" << endl;
    list.printList();

    // ���� addAtIndex
    list.addAtIndex(1, 2); // ����: 1 -> 2 -> 3
    cout << "addAtIndex(1, 2) ��" << endl;
    list.printList();

    // ���� get
    cout << "get(1): " << list.get(1) << endl;

    // ���� deleteAtIndex
    list.DeleteAtIndex(0); // ɾ��ͷ�ڵ�
    cout << "deleteAtIndex(0) ��" << endl;
    list.printList();

    // �ټӼ����ڵ�
    list.addAtHead(5);
    cout << "addAtHead(5) ��" << endl;
    list.printList();

    list.addAtTail(9);
    cout << "addAtTail(9) ��" << endl;
    list.printList();
    return 0;
}
