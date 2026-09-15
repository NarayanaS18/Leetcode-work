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

    void insertInBetween(Node* head){
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }

    void connectNode(Node* head){
        Node* temp = head;

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
    }

    Node* getCopyList(Node* head){
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* temp = head;

        while(temp){
            res->next = temp->next;
            temp->next = temp->next->next;

            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        insertInBetween(head);
        connectNode(head);
        return getCopyList(head);
    }
};