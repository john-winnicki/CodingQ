#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->val<l2->val){
            curr -> next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        else{
            curr -> next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
    }
    if(l1!=nullptr){
        curr-> next = l1;
        return dummy->next;
    }
    else{
        curr-> next = l2;
        return dummy->next;
    }
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int len1, len2;
    cin >> len1 >> len2;

    ListNode* dummy1 = new ListNode(0);
    ListNode *curr = dummy1;
    int input;
    for(int i = 0; i<len1; i++){
        cin>>input;
        ListNode *temp = new ListNode(input);
        curr->next = temp;
        curr = temp;
    }

    ListNode* dummy2 = new ListNode(0);
    curr = dummy2;
    for(int i = 0; i<len2; i++){
        cin>>input;
        ListNode * temp = new ListNode(input);
        curr->next = temp;
        curr = temp;
    }

    ListNode * fin = mergeTwoLists(dummy1->next, dummy2->next);

    curr = fin;
    while(curr!=nullptr){
        cout<<curr->val << "   ";
        curr = curr->next;
    }

	return 0;
}
