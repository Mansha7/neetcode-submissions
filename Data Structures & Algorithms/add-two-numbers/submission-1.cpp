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
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        int carry = 0;
        while(cur1 && cur2){
            int sum = cur1->val + cur2->val + carry;
            carry = sum/10;
            // ListNode* temp = new ListNode();
            // temp->val = sum%10;
            temp->next = new ListNode(sum%10);
            temp=temp->next;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        while(cur1){
            int sum = carry + cur1->val;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp=temp->next;
            cur1=cur1->next;
        }
        while(cur2){
            int sum = carry + cur2->val;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp=temp->next;
            cur2=cur2->next;
        }
        if(carry!=0){
            temp->next = new ListNode(carry);
            // temp=temp->next;
        }
        return ans->next;
    }
};
