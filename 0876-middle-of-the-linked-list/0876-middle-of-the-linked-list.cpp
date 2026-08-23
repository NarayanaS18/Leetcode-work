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
    ListNode* middleNode(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        int st = 0, end = n-1, mid = 0;
        if(n%2 != 0) mid = st + (end-st)/2;
        else{
            mid = (st + (end-st)/2) + 1;
        }

        temp = head;
        int cnt = 0;
        while(temp){
            if(cnt == mid){
                return temp;
            }
            temp = temp->next;
            cnt++;
        }
        return nullptr;
    }
};