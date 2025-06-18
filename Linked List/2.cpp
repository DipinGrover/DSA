#include<bits/stdc++.h>
using namespace std ;

// adding conversion of array to LL and traversl in a LL using 1.cpp file 
class Node{
    public:
    int data; // value
    Node* next; //ptr


    Node(int data1 , Node* next1)
    {
        data = data1;
        next = next1;

    }

    Node(int data1 )
    {
        data = data1;
        next = nullptr;
    }
};

Node* array_to_LL(vector<int> arr)
{
    Node* head = new Node(arr[0]);

    Node* mover = head; // mover that points to head

    for(int i = 1 ; i<arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);

        mover->next  = temp;

        mover = mover->next;
    }

    return head;

}

void traversal_in_LL(Node* head)
{
    Node* temp = head;

    while(temp != NULL) // for reaching out to last node
    {
        //move 
        cout << temp->data  << " ";
        temp = temp->next;

    }
}

Node* deletion_of_head(Node* head)
{
    Node* temp = head;

    head = head->next; // move the head 

    delete temp; // or free(temp);
    return head;
}

Node* delettion_of_tail(Node* head)
{
    Node* temp = head;

    // we have to move until temp->next->next!=null
    // this is the logic here
    while(temp->next->next != NULL)
    {
        // move
        temp = temp->next;


    }
    temp->next = nullptr;
    delete temp->next;

    return head;

}
int main()
{
    vector<int> arr = {2,6,7,8,4,1,9};

    Node* head = array_to_LL(arr);

    // // deletion of head part ---
    // traversal_in_LL(head); // before deletion of head
    // // deletion of head node 
    // head = deletion_of_head(head);
    // cout << endl;
    // traversal_in_LL(head); //after deletion of head






    // deletion of tail part
    traversal_in_LL(head);
    head = delettion_of_tail(head);
    cout << endl;
    traversal_in_LL(head);

}