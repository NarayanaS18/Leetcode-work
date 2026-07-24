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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(0, head);
        ListNode* temp = prev;

        while(temp != nullptr){
            while(temp->next != nullptr && temp->next->val == val){
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        ListNode* ans = prev->next;
        delete prev;
        return ans;
    }
};