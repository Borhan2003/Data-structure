#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    ListNode*next;
    int val;
};
ListNode*head=0;
void Insert(int val)
    {
       ListNode *nn = new ListNode;
        if (head == 0)
        {
            nn->val = val;
            head = nn;
            nn->next = 0;
            
            return;
        }
         ListNode *t = head;
        nn->val= val;

        while (t->next)
        {
            t = t->next;
        }
        t->next = nn;
        nn->next = 0;
      
    }
    void Print(ListNode*head){
         ListNode*t=head;
         while(t){
            cout<<t->val<<" ";
            t=t->next;
         }
         cout<<endl;
    }
     ListNode* Reverse( ListNode*&h){
         ListNode*cur=h;
         ListNode*forward;
         ListNode*prev=0;
         while(cur){
            forward=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forward;
         }
         

         return prev;
    }

int main(){
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Print(head);
    ListNode*Rhead=Reverse(head);
    Print(Rhead);

    return 0;
}