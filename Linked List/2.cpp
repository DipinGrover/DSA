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

Node* delete_kth_node(Node* head , int K)
{
    if(head == NULL)
    {
        // empty LL

        return head;
    }

    if(K==1) // deletion of head node
    {
        Node*temp = head; // temp pointing to head
        head = head->next;  //move the head
        delete temp; // delete temp
        return head;

    }


    // this logic will handle case for deletion of middle node  , tail node , and if node does not exist
    Node* temp = head;
    int cnt = 0;
    Node* prev = NULL;

    while(temp != NULL)
    {
        // move in LL

        cnt++;

        if(cnt ==K)
        {
            // we have to delete this Node

            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}


// delete a given X value Node

Node* delete_X_value_node(Node* head , int X)
{
    // if LL is empty

    if(head == NULL)
    {
        return head;
    }

    // if X is value of first node
    if(head->data ==X)
    {
        // delete this node
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // if X is value of midddle nod e or tail node


    Node* temp = head;
    Node* prev = NULL;
    // no need of count here

    while(temp != NULL) //move in a LL
    {
        if(temp->data ==X)
        {
            // we have to delete this node
            // don't forget to keep track of previous 
            prev->next = temp->next;
            delete temp;
            break;

        }
        prev = temp;
        temp = temp->next;
    }
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






    // // deletion of tail part
    // traversal_in_LL(head);
    // head = delettion_of_tail(head);
    // cout << endl;
    // traversal_in_LL(head);




    // // deletion of kth node
    // traversal_in_LL(head);

    // head = delete_kth_node(head , 8);
    // cout <<endl;
    // traversal_in_LL(head);







    // deletion of given node with value X
    traversal_in_LL(head);
    head = delete_X_value_node(head , 4);
    cout << endl;
    traversal_in_LL(head);
   
}