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


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;

    ListNode* dummy = new ListNode;
    ListNode* curr = dummy;

    while(l1 != nullptr || l2 != nullptr){
        
        int res = carry;

        // cout<< endl << res;
        if(l1!=nullptr){
            res += (l1 -> val);
            l1 = l1 -> next;
        }
        // cout<< endl << res;
        if(l2 != nullptr){
            res += (l2 -> val);
            l2 = l2 -> next;
            // cout << l2;
        }
        // cout<< endl << res;

        // cout<< endl << carry << "   " << res << "   " << res/10 << endl;

        carry = res/10;

        ListNode *temp = new ListNode(res%10);
        curr -> next = temp;
        curr = curr -> next;
    }

    if(carry!=0){
        ListNode *temp = new ListNode(carry);
        curr -> next = temp;
        curr = curr -> next;
    }

    return dummy -> next;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int len1, len2;
    cin >> len1 >> len2;

    ListNode *dummy1 = new ListNode(0);
    ListNode *curr1 = dummy1;
    int input;
    for(int i = 0; i<len1; i++){
        cin >> input;
        ListNode *temp = new ListNode(input);
        curr1 -> next = temp;
        curr1 = temp;
    }

    ListNode *dummy2 = new ListNode(0);
    ListNode *curr2 = dummy2;
    for(int i = 0; i<len2; i++){
        cin >> input;
        ListNode *temp = new ListNode(input);
        curr2 -> next = temp;
        curr2 = temp;
    }

    ListNode* fin = addTwoNumbers(dummy1->next, dummy2->next);

    while(fin -> next!= nullptr){
        cout << fin -> val << "   ";
        fin = fin -> next;
    }
    cout << fin -> val;

	return 0;
}
