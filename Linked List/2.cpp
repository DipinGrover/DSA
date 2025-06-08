#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* convert_array_to_LL(vector<int> & arr)
{
    Node* head = new Node(arr[0]); // head always points to 0th index element of array
    Node* mover = head; // mover initially pointing towards head

    for(int i = 1 ; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]); // make a new node temp 

        mover->next = temp; // mover your next is temp;

        mover = temp;  // we can also write mover = mover->next this is for moving the mover 
    }

    return head;
}

void traversal_in_ll(Node* head)
{
    Node* temp = head; //temp initially points to head

    while(temp != NULL)
    {
        // we will move

        cout << temp->data << " ";

        temp= temp->next;
    }


}

Node* delete_head_of_LL(Node* head)
{

    if(head == NULL) return NULL; // no element

    if(head->next == NULL ) return NULL; // only one element

    
    Node* temp = head; // temp points to head

    head = head->next; // move the head

    delete temp; //delete temp

    return head; // returning the new head

    // edge cases

    

}

Node* delete_tail_of_ll(Node* head)
{
    if(head== NULL) //empty ll
    {
        return NULL;
    }
    if(head->next == NULL) // single element LL
    {
        return NULL;
    }

    //else move till second last node 

    Node* temp = head;

    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    // we need to remove its next element
    delete temp->next; // delete next node of temp
    temp->next = nullptr; // temp next is now nullptr
    return head;


}

int main()
{
    vector<int> arr = {2,6,7,8,9,1,3};


    // converting vector to a LL

    Node* head = convert_array_to_LL(arr);

    // cout << head->data << endl;


    // traversal in LL
    traversal_in_ll(head);


    // deletion of head
    // head = delete_head_of_LL(head);
    // cout << endl;
    // traversal_in_ll(head);



    // deletion of tail 
    head = delete_tail_of_ll(head);
    cout << endl;
    traversal_in_ll(head);

}