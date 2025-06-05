#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data ;
    Node* next;


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

Node* array_to_LL(vector<int> & arr)
{
    Node* head  = new Node(arr[0]); // head always points to 0th index element of array
    Node* mover = head; // mover initially points to head

    for(int i =1 ; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]); //temp starts from index and goes on till last element

        mover->next = temp; // mover next is temp

        mover =mover-> next; // mave the mover 
    }

    return head;
}


void traversal_in_LL(Node* head)
{
    Node* temp = head; //temp pointing towards head

    while(temp!= NULL) //till temp element is not null move 
    {
        // move in LL

        cout << temp->data << " ";
        temp = temp->next;
    }

}

int lengthofLL(Node* head)
{
    int cnt =0;
    Node* temp = head;

    while(temp!= NULL) //move till temp != NULL
    {
        cnt++;

        temp = temp->next; // move the temp
    }
    return cnt;
}


bool checkifelement_is_present_or_not(Node* head , int val)
{
    Node* temp  = head; //temp pointing to head

    while(temp!= NULL) // hwen temp is not null move
    {
        if(temp->data == val) // if temp -> data == value return true else false;
        {
            return true;
        }
        temp = temp->next; // move temp to next
    }
    return false; // else return false
}

int main()
{
    vector<int> arr = {12,3,1,7,9,4,3};
    Node* y = new Node(arr[0]);
    // cout << y->data ;



    //conversion from array to LL
    Node* head =  array_to_LL(arr);
    // cout << head->data;



    // traversl in linked list
    // traversal_in_LL(head);


    // length of LL
    // int length = lengthofLL(head);
    // cout << length;



    // search if element is present
    bool if_present = checkifelement_is_present_or_not(head , 3);
    cout << if_present;
}