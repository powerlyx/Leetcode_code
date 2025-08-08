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

    // 创建链表
    void create_MyLinkList(){
         struct LinkNode* cur =  dummy;
         int x;

         while(cin >> x ){
           cur->next= new LinkNode(x);
            cur = cur->next;
            _size++; // 维护长度
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
    cout << "初始链表：" << endl;
    list.printList(); // 空链表

    //测试创建链表
    cout << "请输入链表节点值（用空格隔开，Ctrl+D 结束）:" << endl;
    list.create_MyLinkList();
    list.printList(); // 创建后的链表

    // 测试 addAtHead
    list.addAtHead(1);
    cout << "addAtHead(1) 后：" << endl;
    list.printList();

    // 测试 addAtTail
    list.addAtTail(3);
    cout << "addAtTail(3) 后：" << endl;
    list.printList();

    // 测试 addAtIndex
    list.addAtIndex(1, 2); // 链表: 1 -> 2 -> 3
    cout << "addAtIndex(1, 2) 后：" << endl;
    list.printList();

    // 测试 get
    cout << "get(1): " << list.get(1) << endl;

    // 测试 deleteAtIndex
    list.DeleteAtIndex(0); // 删除头节点
    cout << "deleteAtIndex(0) 后：" << endl;
    list.printList();

    // 再加几个节点
    list.addAtHead(5);
    cout << "addAtHead(5) 后：" << endl;
    list.printList();

    list.addAtTail(9);
    cout << "addAtTail(9) 后：" << endl;
    list.printList();
    return 0;
}
