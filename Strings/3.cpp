#include <iostream>
using namespace std;
int Length_of_string(char name[])
{
    int count = 0;
    for(int i = 0 ;name[i] != '\0'; i++)
    {
        count++;


    }

    return count;

}

void reverse_string(char name[])
{
    int i = 0;
    int j = Length_of_string(name) -1;

    while(i<j)
    {
        swap(name[i],name[j]);
        i++;
        j--;
    }

    cout << name;
}
int main()
{
    char name[20];

    cin.getline(name, 20);

    reverse_string(name);
}