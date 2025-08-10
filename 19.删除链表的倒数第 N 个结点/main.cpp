#include <iostream>

using namespace std;

struct LinkNode {
    int val;
    struct LinkNode* next;
    LinkNode (int x): val(x), next(nullptr){}  // 构造函数
};
// 创建 MyLinkList类
class MyLinkList{
public:
    LinkNode* dummy;
    int _size;

    MyLinkList(){
        dummy = new LinkNode(-1);
        _size = 0;
    }

    void CreateLinkList(){
     int len;
        cout << "请输入链表长度：" << endl;
        cin >> len;

        cout << "请输入链表节点：" << endl;
        LinkNode* curr = dummy;
        for (int i = 0; i < len; i++) {
            int x; cin >> x;
            LinkNode* temp = new LinkNode(x);
            curr->next = temp;
            curr = curr->next;
            _size++;
        }
    }

        void PrintList(){
   struct LinkNode* cur =  dummy->next;
          while( cur!= nullptr){
            cout << cur->val;
            if (cur->next != nullptr) cout<< "->";
            cur = cur->next;
          }
             cout <<"->NULL" << endl;
        }

        LinkNode* removeNthFromEnd(int n) {
            LinkNode* curr = dummy;
            LinkNode* fast = dummy; // 这里fast 最好也等于dummy出发
            // 快指针先走n+1步
            for(int i=0; i<n+1; i++){
                fast = fast->next;
            }
            //   然后同时走，这样当fast到尾部的时候，curr就是指向要删除的节点的前驱节点
            while( fast!= nullptr){
                curr = curr->next;
                fast = fast->next;
            }
            curr->next = curr->next->next;
            _size--;
            return dummy->next;
        }

} ;

int main()
{
    cout << "Hello world!" << endl;
    MyLinkList list;

    list.CreateLinkList();
    cout<< "删除前："<< endl;
    list.PrintList();

    int n;
    cout<<"请输入要删的倒数第n个节点："<<endl;
    cin >>n;
    if (n <= 0 || n > list._size) {
    cout << "输入的 n 不合法！" << endl;

}
    list.removeNthFromEnd(n);
    cout<< "删除后："<<endl;
    list.PrintList();

    return 0;
}
