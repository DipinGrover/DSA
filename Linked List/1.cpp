#include <bits/stdc++.h>
using namespace std;


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

int cnt_the_nodes(Node* head)
{
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        // move 
        cnt++;

        temp = temp->next;

        

    }

    return cnt;
}

// search an element in LL
bool search_an_element_in_LL(Node* head , int ele)
{
    Node* temp = head;

    while(temp != NULL)
    {
        //move in the array

        if(temp->data == ele)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


int main()
{
    vector<int> arr = {12,6,8,9,2,3,5,4};

    Node* head = array_to_LL(arr);

    // cout << head->data;

    // traversal_in_LL(head);



    //length of LL
    // int length = cnt_the_nodes(head);
    // cout << length;



    // search an element in LL
    bool if_present = search_an_element_in_LL(head , 15);
    cout <<  if_present  ;
    
}