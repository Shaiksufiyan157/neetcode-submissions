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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1;
        ListNode*  head2=list2;
        ListNode* dummyList=new ListNode(-1);
        ListNode* dTemp=dummyList;

        while(head1 && head2){
            
            if(head1->val<=head2->val){
                dTemp->next=head1;
                dTemp=dTemp->next;
                head1=head1->next;
            }
        else{
                dTemp->next=head2;
                dTemp=dTemp->next;
                head2=head2->next;
        }
        }

        if(head1){
                dTemp->next=head1;
        }
        if(head2){
                dTemp->next=head2;
        }
        return dummyList->next;
    }
};
