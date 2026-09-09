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

    ListNode* find(ListNode* temp, int k){
        int cnt = 1;
        while(temp){
            if(cnt == k){
                return temp;
            }
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        if(k % len == 0) return head;
        k = k % len;

        tail->next = head;

        ListNode* newLastNode = find(head, len-k);
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};