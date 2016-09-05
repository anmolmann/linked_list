/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    Node *temp = head -> next, *prev = head;
    while(temp) {
        if(prev -> data == temp -> data) {
            prev -> next = temp -> next;
            temp = temp -> next;
        }
        else {
            prev = temp;
            temp = temp -> next;
        }
    }
    return head;
}
