/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;

        //insert copy node in between
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;

            temp = temp->next->next;
        }

        //connect random pointer of the copy nodes
        temp = head;
        while(temp){
            Node* copy = temp->next;
            if(temp->random != NULL){
                copy->random = temp->random->next;
            }
            else{
                copy->random = NULL;
            }
            temp = temp->next->next;
        }

        //now reconnect original next and connect copy next to copy nodes
        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while(temp){
            res->next = temp->next;
            temp->next = temp->next->next;
            
            temp = temp->next;
            res = res->next;            
        }

        return dummy->next;

    }
};