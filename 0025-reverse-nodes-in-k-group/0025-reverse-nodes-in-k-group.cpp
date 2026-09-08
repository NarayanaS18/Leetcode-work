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

    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newhead;
    }

    ListNode* findKNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp){
            ListNode* kNode = findKNode(temp, k);

            if(kNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverseList(temp);

            if(temp == head){
                head = kNode;
            }
            else{
                prevNode->next = kNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};