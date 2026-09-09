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

    void Reverse(vector<int>& arr, int st, int end){
        while(st < end){
            swap(arr[st], arr[end]);
            st++;
            end--;
        }
    }

    void Rotate(vector<int>& arr, int k){
        int n = arr.size();
        if(n < k) k = k%n;
        Reverse(arr, 0, n-1);
        Reverse(arr, 0, k-1);
        Reverse(arr, k, n-1);
    }

    ListNode* convertArr2LL(vector<int>& arr){
        if(arr.empty()) return NULL;
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;

        for(int i=1; i<arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = mover->next;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        vector<int> arr;

        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        Rotate(arr, k);

        ListNode* newhead = convertArr2LL(arr);

        return newhead;
    }
};