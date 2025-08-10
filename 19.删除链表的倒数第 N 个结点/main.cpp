#include <iostream>

using namespace std;

struct LinkNode {
    int val;
    struct LinkNode* next;
    LinkNode (int x): val(x), next(nullptr){}  // ���캯��
};
// ���� MyLinkList��
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
        cout << "�����������ȣ�" << endl;
        cin >> len;

        cout << "����������ڵ㣺" << endl;
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
            LinkNode* fast = dummy; // ����fast ���Ҳ����dummy����
            // ��ָ������n+1��
            for(int i=0; i<n+1; i++){
                fast = fast->next;
            }
            //   Ȼ��ͬʱ�ߣ�������fast��β����ʱ��curr����ָ��Ҫɾ���Ľڵ��ǰ���ڵ�
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
    cout<< "ɾ��ǰ��"<< endl;
    list.PrintList();

    int n;
    cout<<"������Ҫɾ�ĵ�����n���ڵ㣺"<<endl;
    cin >>n;
    if (n <= 0 || n > list._size) {
    cout << "����� n ���Ϸ���" << endl;

}
    list.removeNthFromEnd(n);
    cout<< "ɾ����"<<endl;
    list.PrintList();

    return 0;
}
