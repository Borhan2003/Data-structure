#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    ListNode *next;
};
bool hasCycle(ListNode *&head)
{

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != 0 and fast->next != 0)
    {

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{
    return 0;
}
