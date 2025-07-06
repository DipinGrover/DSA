#include <iostream>
#include  <string>
using namespace std;

int return_no_of_vowels(string str)
{
    // count vowels in a string 

     

    int count = 0;

    for(int i = 0 ; i<str.size() ;i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int ans = return_no_of_vowels("dipin grover");

    cout << ans;

}