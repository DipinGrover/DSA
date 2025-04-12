#include <iostream>
#include <vector>
using namespace std;

struct Node
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

};

int main()
{
    vector<int> arr = {12,5,8,1};

    Node* y = new Node(arr[0],nullptr);

    cout << y << endl;
    cout << y->data << endl;
    cout << y->next << endl;
    
}