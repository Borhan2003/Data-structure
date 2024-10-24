// onek somoi mid er agher value janar dorkar hoi . tokon duita way ache :
void slowfast - 1()
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
}
void slowfast - 2
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next and fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
}