#include<iostream>
using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *n_from_end = head;
    for(int i = 0; i<n-1; i++) n_from_end = n_from_end->next;

    ListNode dummy = ListNode(0);
    dummy.next = head;
    
    ListNode* prev = &dummy;
    ListNode* curr = head;

    while(n_from_end->next != nullptr){
        prev = curr;
        curr = curr->next;
        n_from_end = n_from_end->next;
    }

    prev->next = curr->next;
    return dummy.next;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int n;
    cin >> n;

    ListNode *dummy = new ListNode(0);
    ListNode* curr = dummy;
    // cout << curr.val;
    int input;
    while(cin>>input){
        ListNode *temp = new ListNode(input);
        curr -> next = temp;
        // cout << endl << temp << endl;
        // cout << &curr << "    " << curr -> next << endl;
        curr = curr->next;
        // cout << &curr << "    " << curr -> next << endl << endl;
    }

    // cout << curr->val;
    // cout << curr->next;

    curr = dummy;
    // cout << curr->val;
    // while(curr != nullptr){
    //     cout << curr -> val << "  ";
    //     curr = curr -> next;
    // }

    ListNode *fin = removeNthFromEnd(dummy->next, n);

    while(fin!=nullptr){
        cout << fin->val << "   ";
        fin = fin->next;
    }

    // ListNode dummy = ListNode(57);
    // cout << &dummy << "   " << dummy.val << "    " << &dummy.val<< endl;
    // ListNode curr = dummy;
    // curr.val = 52;
    // cout << &dummy << "   " << dummy.val << "    " << &dummy.val<< endl;
    // cout << &curr << "   " << curr.val << "    " << &curr.val;

	return 0;
}
