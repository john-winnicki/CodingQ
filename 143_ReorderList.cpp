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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode* temp = curr-> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while(curr!=nullptr){
            len++;
            curr = curr -> next;
        }
        if(len<=1) return;
        len /= 2;
        
        ListNode* head1 = head;
        
        ListNode* head2 = head;
        while(len-->0) head2 = head2->next;
        
        head2 = reverse(head2);
        
        curr = head2;
        // while(curr!=nullptr){
        //     cout<<curr->val<<endl;
        //     curr = curr->next;
        // }
        
        while(head1->next!=nullptr && head2->next!=nullptr){
            ListNode *temp1 = head1 -> next;
            ListNode *temp2 = head2 -> next;
            head1 -> next = head2;
            head2 -> next = temp1;
            head1 = temp1;
            head2 = temp2;
        }
        
        head1 -> next = head2;
        if(head2==nullptr) return;
        head2 -> next = nullptr;
    }
};