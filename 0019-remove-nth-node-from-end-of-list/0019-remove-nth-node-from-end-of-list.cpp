/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        if(cnt == n){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        int pos = cnt - n;
        temp = head;

        //the temp will stop just before the node it need to delete
        while(temp != NULL){
            pos--;
            if(pos == 0){
                break;
            }
           
            temp = temp->next;
        }
        ListNode* temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        return head;
    }
};