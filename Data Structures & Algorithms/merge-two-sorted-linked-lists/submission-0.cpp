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
        ListNode* head = new ListNode();
        ListNode* temp = head;
        ListNode* cur1=list1;
        ListNode* cur2=list2;
        while(cur1 && cur2) {
            cout<<"in the night"<<endl;
            if(cur1->val<=cur2->val){
                temp->next = cur1;
                cur1=cur1->next;
            }else if(cur2->val<cur1->val){
                temp->next = cur2;
                cur2=cur2->next;
            }
            temp=temp->next;
        }

        while(cur1){
            temp->next=cur1;
            cur1=cur1->next;
            temp=temp->next;
        }

        while(cur2){
            temp->next=cur2;
            cur2=cur2->next;
            temp=temp->next;
        }

        return head->next;
    }
};
