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
                unordered_map<Node*,Node*> map;
        Node* temp=head;

        while(temp){
            Node* curr=new Node(temp->val);
            map[temp]=curr;
            temp=temp->next;
        }
        Node* dummyList=new Node(-1);
        Node* dTemp=dummyList;
        temp=head;

        while(temp){
            Node* curr=map[temp];
            curr->next=map[temp->next];
            if(temp->random) {
                curr->random=map[temp->random];
            }
            dTemp->next=curr;
            dTemp=curr;
            temp=temp->next;
        }

        return dummyList->next;
    }
};
