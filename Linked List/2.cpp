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




// 1. deletion of head in ll

Node* delete_head_of_ll(Node* head)
{
    if(head == NULL)
    {
        // empty ll
        return NULL;
    }

    if(head->next == NULL)
    {
        // single element ll and that element will be the head
        delete head;
        return NULL;
    }

    Node* temp = head; // temp pointing towards head

    head = head->next; // move head to next

    delete temp;

    return head;

}


// 2. delete tail

Node* delete_tail_of_ll(Node* head)
{
    if(head == NULL)
    {
        // empty ll 
        return NULL;
    }

    if(head->next == NULL)
    {
        // single node that will be head as well as tail of ll
        delete head;
        return NULL;
    }

    Node* temp = head;

    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next; // delete temp next

    temp->next = nullptr; // now temp->next is nullptr

    return head; // return head
}


// 3. delete kth node of ll

Node* delete_kth_node(Node* head , int k)
{
    if(head == NULL)
    {
        // empty ll
        return NULL;
    }

    if(k==1)
    {
        // delete head of ll
        head = delete_head_of_ll(head);
        return head;
    }

    int count = 0;
    Node* temp = head;
    Node* back = NULL;

    while(temp != NULL)
    {
        count++;
        if(count == k)
        {
            // this is the node we wanted to delete  

            back->next = temp->next;
            delete temp;
            break;
        }
        back = temp;
        temp = temp->next;
    }

    return head;

}

int main()
{
    vector<int> arr = {2,7,1,5,9,4,3,11};



    // for converting array to ll
    Node* head = convert_array_to_ll(arr);




    // for traversing in a ll
    traversal_in_ll(head);



    // // for deletion of head in ll
    // head = delete_head_of_ll(head);

    // cout << endl;

    // traversal_in_ll(head);





    // // for deletion of tail in ll
    // head = delete_tail_of_ll(head);

    // cout << endl;

    // traversal_in_ll(head);





    // for deletion of kth node
    head = delete_kth_node(head , 7);

    cout << endl;

    traversal_in_ll(head);
}