#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1 , Node* next1)
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

Node* convert_array_to_ll(vector<int> &arr)
{
    Node* head = new Node(arr[0]);

    Node* mover = head; // mover node currently pointing to head

    for(int i = 1 ; i<arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]); // temp always points to new node

        mover->next = temp; // mover next is temp

        mover = mover->next; // moving the mover

    }

    return head;
}

void traversal_in_ll(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
}

// deletion of node in ll


// 1. deletion of head
Node* delete_head_of_ll(Node* head)
{
    if(head == NULL)
    {
        // if empty ll
        return NULL;
    }

    if(head->next == nullptr)
    {
        // single element ll and that node will be the head
        delete head;

        return NULL;
    }

    Node* temp = head; // temp points to head

    head = head->next; // move the head

    delete temp;

    return head;
}

int main()
{
    vector<int> arr = {2,7,1,5,9,4,3,11};



    // for converting array to ll
    Node* head = convert_array_to_ll(arr);




    // for traversing in a ll
    traversal_in_ll(head);



    // for deletion of head in ll
    head = delete_head_of_ll(head);
    cout << endl;
    traversal_in_ll(head);
}