#include <iostream>
using namespace std;
bool if_palindrome_app_1(string str)
{
    string rev = "";

    

    for(int i = str.size()-1 ; i>=0 ; i--)
    {
        rev+= str[i];
    }


    for(int i = 0 ; i<str.size() ; i++)
    {
        // compare both 
        if(str[i] != rev[i])
        {
            return false;
        }
    }

    return true;
}

bool if_palindrome_app_2(string str)
{
    // without extra string used 

    int start = 0;
    int end = str.size()-1;

    while(start < end)
    {
        // we will check the first and last elements 
        if(str[start] != str[end])
        {
            return false;

        }
        start++;
        end--;
    }

    return true;
}

int main()

{
    // check if string is palindrome or not ?

    string str = "dipin";

    // bool ans = if_palindrome_app_1(str);

    // cout << ans;

    bool ans = if_palindrome_app_2(str);

    cout << ans;

}