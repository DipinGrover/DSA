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
    if(head ==NULL)
    {
        // empty LL
        return head;
    }

    if(head->next == nullptr)
    {
        // single node LL
        delete head;
        return NULL;
    }
    Node* temp = head;

    head = head->next; // move the head 

    delete temp; // or free(temp);
    return head;
}

Node* delettion_of_tail(Node* head)
{
    if(head==NULL)
    {
        // empty LL
        return head;
    }
    if(head->next==nullptr)
    {
        // single node that will be head and tail 

        delete head;

        return NULL;
    }
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



// insertion part 

Node* insertion_before_head(Node* head , int ele)
{
    
    Node* temp = new Node(ele); // new node

    temp->next = head; // now temp->next is head

    head = temp; // new head is temp node now 


    return head;
}


Node* insertion_after_tail(Node* head , int ele)
{
    if(head == NULL)
    {
        Node* temp = new Node(ele);
        return temp;
    }
    Node* temp = head;
    while(temp != NULL)
    {
        //move in LL

        if(temp->next == nullptr)
        {
            // insert node here 
            Node* tail = new Node(ele); //new node
            temp->next = tail; //temp next is now this new node
            break;
        }

        temp = temp->next; //keep moving
    }
    return head;
}

Node* insertion_at_Kth_position(Node* head , int ele , int K)
{
    if(head == NULL)
    {
        // empty LL
        // we can only insert at head
        if(K==1)
        {
            // inseert at head
            Node* temp = new Node(ele);
            temp->next = head;
            return temp;
        }
        return NULL;
    }

    if(K==1)
    {
        // insertion at head
        Node* temp = new Node(ele);
        temp->next = head;
        return temp;
    }

    // for cases insertion in betwwen two nodes or at tail logic
    Node* temp = head;
    Node* new_one = new Node(ele);
    int cnt = 0;
    while(temp != NULL)
    {
        // move in LL
        cnt++;

        if(cnt == K-1)
        {
            // we have to stop here
            new_one->next = temp->next;
            temp->next = new_one;
            break;
        }

        temp = temp->next;
    }
    return head;
}


Node* insertion_before_a_specific_node_x(Node* head , int ele , int x)
{

    // int ele is the value of new node
    // int x is the value of node before which we have to insert a new node
    if(head==NULL)
    {
        // empty LL
        // insert kis node ke phle karoge 
        return head;
    }
    if(head->data == x)
    {
        // insert before head
        Node* temp = new Node(ele);
        temp->next = head;
        return temp;
    }

    Node* temp= head;
    Node* prev = NULL;
    Node* new_one = new Node(ele);
    while(temp != NULL)
    {
        // move in LL

        if(temp->data  == x)
        {
            // wr have insert new node before it
            new_one->next = temp;
            prev->next = new_one;
            break;
        }
        prev = temp;
        temp = temp->next;
        

    }
    return head;

}



int main()
{
    vector<int> arr = {2,7,1,9,6,3,8};

    Node* head = array_to_LL(arr);

    // deletion part


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







    // // deletion of given node with value X
    // traversal_in_LL(head);
    // head = delete_X_value_node(head , 4);
    // cout << endl;
    // traversal_in_LL(head);








    // insertion part now 


    // // insert before head of LL
    // traversal_in_LL(head);
    // head = insertion_before_head(head , 3);
    // cout << endl;
    // traversal_in_LL(head);





    // ek baar if head == NULL ho toh wo case dekhna h 
    // // insert after tail 
    // traversal_in_LL(head);
    // head=insertion_after_tail(head , 3);
    // cout << endl;
    // traversal_in_LL(head);






    // // insertion at Kth position in a LL
    // traversal_in_LL(head);
    // head = insertion_at_Kth_position(head,4,8);
    // cout << endl;
    // traversal_in_LL(head);









    // insert a node before a node whose value is x
    traversal_in_LL(head);
    head = insertion_before_a_specific_node_x(head,4,8);
    cout << endl;
    traversal_in_LL(head);
   
}