

 struct ListNode {
     int val;
    struct ListNode *next;
 };
 


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL;
    struct ListNode* head1 = head;
    if (head == NULL)
        return NULL;
    while (head1 != NULL)
    {
        if (prev == NULL && head1->val == val)
        {
            struct ListNode* tmp = head1;
            head1 = head1->next;
            head = head1;
            free(tmp);
        }
        else if (head1->val != val)
        {
            prev = head1;
            head1 = head1->next;
        }
        else if (prev != NULL)
        {
            //É¾³ı
            prev->next = head1->next;
            free(head1);
            head1 = prev->next;
        }
    }
    return head;

}