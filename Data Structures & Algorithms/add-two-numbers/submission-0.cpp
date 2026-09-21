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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=l1;
        ListNode* head2=l2;

        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;

        int carry=0;
        int sum;
        while(head1 || head2){
            ListNode* cur=new ListNode();
            if(head1 && head2){
                sum=(head1->val + head2->val + carry);
                carry=(sum)/10;
                cur->val=sum%10;
                head1=head1->next;
                head2=head2->next;
            }
            else if(head1){
                sum=(carry+head1->val);
                carry=(sum)/10;
                cur->val=sum%10;
                head1=head1->next;
            }
           else{
                sum=(carry+head2->val);
                carry=(sum)/10;
                cur->val=sum%10;
                head2=head2->next;
            }
            temp->next=cur;
            temp=temp->next;
        }
        if(carry){
            ListNode* cur=new ListNode(carry);
            temp->next=cur;
            temp=temp->next;
        }
        return dummyNode->next; 
    }
};
