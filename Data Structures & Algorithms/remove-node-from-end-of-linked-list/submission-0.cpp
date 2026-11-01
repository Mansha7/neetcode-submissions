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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* cur=head;
        while(cur){
            cnt++;
            cur=cur->next;
        }
        // iterate for the cur-nth node from start
        int k=0;
        cur=head;
        ListNode* prev = NULL;
        while(cur && k<=cnt-n-1){
            k++;
            prev=cur;
            cur=cur->next;
        }
        ListNode* temp = cur->next;
        if(!prev && temp){
            return temp;
        }else if(!prev && !temp){
            return NULL;
        }
        prev->next = temp;
        return head;
    }
};
