#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1 , Node* next1 ,Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1)
    {
        data = data1;
    }
};

Node* array_to_DLL(vector<int> & arr)
{
    Node* head = new Node(arr[0]);

    Node* prev = head;

    for(int i = 1 ; i<arr.size() ; i++)
    {
        Node* temp = new Node(arr[i] , nullptr , prev);

        prev->next = temp;

        prev = temp;
    }

    return head;
}

void traversal_in_DLL(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        // move in DLL
        cout << temp->data  << " ";
        temp = temp->next; 
    }
}
int length_of_DLL(Node* head)
{
    int cnt = 1;
    Node* temp = head;

    while(temp->next !=  NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// deletion in DLL

Node* deletion_of_head(Node*head)
{

    // not working for single node dont know why
    if(head == NULL)
    {
        // empty LL
        return NULL;
    }
    if(head->next== NULL)
    {
        delete head;
        return NULL;
    }
    Node* temp = head;

    head = head->next;

    temp->next = nullptr;
    temp->prev = nullptr;

    head->prev = nullptr;

    delete temp;

    return head;
}

Node* deletion_of_tail(Node* head)
{
    // if empty DLL
    if(head ==NULL)
    {
        return NULL;
    }
    // if only one node thta will be head and tail 
    if(head->next == nullptr)
    {
        delete head;

        return NULL;
    }

    Node* temp = head;

    while(temp->next !=  NULL)
    {
        // this is not the last node
        // we need to move
        temp = temp->next;
    }

    Node* new_tail = temp->prev;

    new_tail->next = nullptr;

    temp->prev = nullptr;

    delete temp;

    return head;
}


Node* deletion_of_kth_node(Node* head , int K)
{
    // running fine on online compiler 
    if(head == NULL)
    {
        // empty LL`
        // we cannot delete anything

        return NULL;

    }

    if(head->next == NULL)
    {
        // only one node in the linked list 
        // we can only delete first node
        if(K==1)
        {   
            // deletion of first node 
            delete head;
            return NULL;
        }
    }

    if(K==1)
    {
        // deletion of head node

        Node* temp  = head;
        head = head->next;
        temp->next = nullptr;
        head->prev = nullptr;

        return head;
    }

    if(K == length_of_DLL(head))
    {
        // it means we want to delte the tail node 

        Node* temp = head;

        while(temp->next != NULL)
        {
            // move in LL
            temp = temp->next;
            
        }
        Node* new_tail = temp->prev;
        new_tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;

    }

    // if not done till yet 
    // traverse the LL
    int cnt = 0;
    Node* temp = head;
    while(temp->next->next != NULL)
    {
        cnt++;
        if(cnt == K)
        {
            // this is the  node we want to delete 
            Node* back = temp->prev;
            Node* front = temp->next;
            temp->next = nullptr;
            temp->prev = nullptr;
            back->next = front;
            front->prev = back;
            delete temp;
            break;
        }
        // traverse 
        temp = temp->next;
    }
    return head;
}

Node*  delete_node(Node* head , Node* temp)
{
    // temp is the node we want to delete 
    


    Node* front = temp->next;
    Node* back = temp->prev;

    if(front == NULL)
    {
        // it means we are on the last node  and we want to delete it 

        temp->prev = nullptr;
        back->next = nullptr;
        delete temp;
        return head;
    }

    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {5,6,9,1,2,4};


    Node* head = array_to_DLL(arr);

    
    // cout << head->data;


    // traversal_in_DLL(head);





    // delegtion of node

    // //deletion of head
    // traversal_in_DLL(head);
    // head = deletion_of_head(head);
    // cout << endl;
    // traversal_in_DLL(head);





    // // deletion of tail 
    // traversal_in_DLL(head);
    // head = deletion_of_tail(head);
    // cout <<endl;
    // traversal_in_DLL(head);





    // int count = length_of_DLL(head);
    // cout << count;
    // // deletion of tkth node
    // traversal_in_DLL(head);
    // head = deletion_of_kth_node(head,1);
    // cout <<endl;
    // traversal_in_DLL(head);






    


    // delete the node 
    traversal_in_DLL(head);

    head =  delete_node(head , head->next->next);
    cout <<endl;
    traversal_in_DLL(head);

    


}