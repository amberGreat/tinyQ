

ListNode* slow = head;
ListNode* fast =head->next;
 while(fast && fast->next){
    fast= fast->next->next;
    slow = slow->next;
}

// slow is the middle node;
