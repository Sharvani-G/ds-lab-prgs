/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp = head, *follow = NULL;
    while (temp != NULL) {
        if (temp->val == val) {
            struct ListNode *toDelete = temp;
            if (follow == NULL) {
                head = temp->next;
                temp = head;
            } else {
                follow->next = temp->next;
                temp = temp->next;
            }
            free(toDelete);
        } else {
            follow = temp;
            temp = temp->next;
        }
    }
    return head;
}
