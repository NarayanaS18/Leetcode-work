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

    ListNode* convertArr2LL(vector<int>& arr){
        int n = arr.size();
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;

        for(int i=1; i<n; i++){
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = mover->next;
        }

        return head;
    }

    void Reverse(vector<int>& arr, int st, int end){
        int n = arr.size();
        while(st <= end){
            swap(arr[st], arr[end]);
            st++;
            end--;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;

        vector<int> arr;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        if(arr.empty()) return NULL;

        for(int i=0; i+k<=n; i+=k){
            Reverse(arr, i, i+k-1);
        }

        ListNode* newhead = convertArr2LL(arr);

        return newhead;
    }
};