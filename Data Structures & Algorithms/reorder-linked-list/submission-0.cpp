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
        ListNode* temp=head;
        ListNode* prev=nullptr;

        while(temp){
            ListNode* ahead=temp->next;
            temp->next=prev;
            prev=temp;
            temp=ahead;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head && !head->next) return;

        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* head2=slow->next;
        slow->next=NULL;
        ListNode* head1=head;

        head2=reverseList(head2);

        ListNode* temp1=head1;
        ListNode* temp2=head2;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;

        while(temp2){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;

            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
        if(temp1){
            temp->next=temp1;
        }
    }
};
