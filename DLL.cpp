#include <iostream>
using namespace std;
struct Node {
   int data;
   Node *prev;
   Node *next;
};
struct Node* head = NULL;
void insert_front(int newdata) {
   Node* newnode = new Node();
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}
void display() {
   Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
   insert_front(3);
   insert_front(1);
   insert_front(7);
   insert_front(2);
   insert_front(9);
   cout<<"The doubly linked list is: ";
   display();
   return 0;
}