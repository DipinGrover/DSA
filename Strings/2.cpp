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
int main()
{
    char str[20];

    cin >> str;


    cout << Length_of_string(str);


}