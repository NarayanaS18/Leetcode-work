/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* collissionPoint(ListNode *h1, ListNode *h2, int diff){
        //h1 is smaller len and h2 is bigger len
        ListNode* temp1 = h1;
        ListNode* temp2 = h2;
        for(int i=0; i<diff; i++){
            temp2 = temp2->next;
        }

        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int l1 = 0, l2  = 0;

        while(temp1 != NULL){
            l1++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            l2++;
            temp2 = temp2->next;
        }
        if(l1 < l2){
            return collissionPoint(headA, headB, l2-l1);
        }
        else{
            return collissionPoint(headB, headA, l1-l2);
        }
        return NULL;
    }
};