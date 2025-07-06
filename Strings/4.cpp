#include <iostream>
using namespace std;
int main()
{
    string str;

    cin >> str;

    cout << str << endl;

    for(int i = 0 ; i<str.size() ;i++)
    {
        if(i%2 ==0)
        {
            // even index

            str[i] = 'a';
        }
    }

    cout << str <<endl;
}