#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    public:
    // constructor
    Node(int data1 , Node* next1)
    {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

};

Node* convert_array_to_ll(vector<int> & arr) // we have to return head of ll
{
    Node* head = new Node(arr[0]); // head points to first element of array

    Node* mover = head; // mover points to head

    for(int i = 1 ; i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]); // temp is the new node and mover next should be temp
        
        mover->next = temp; // mover's next is temp

        mover = temp; // we are moving mover
    }

    return head;
}

void traversal_in_ll(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        // when temp->next != nullptr then move

        cout << temp->data << " ";

        temp = temp->next;
    }
}

int length_of_ll(Node* head)
{
    // using the traversal

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        // when temp->next != nullptr then move
        cnt++;
        // cout << temp->data << " ";

        temp = temp->next;
    }

    return cnt;
}

bool search_for_kth_element(Node* head , int ele)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == ele)
        {
            return true;
        }
        
        // move to next
        temp = temp->next;
    }
    return false;
}

int main()
{
    vector<int> arr = {16,9,12,5,8,1};

    Node* y = new Node(arr[0],nullptr);

    // cout << y << endl;
    // cout << y->data << endl;
    // cout << y->next << endl;




    // converting an array to a ll
    Node* head = convert_array_to_ll(arr);
    // cout << head->data;




    // // traversal in ll
    // cout << endl;
    // traversal_in_ll(head);




    // // length of ll
    // int length = length_of_ll(head);
    // cout << length;




    // search for kth element
    bool ans = search_for_kth_element(head , 15);
    cout << ans;
}