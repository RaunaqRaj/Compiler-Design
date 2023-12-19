#include <iostream>
#include <string>
using namespace std;

int main()
{
    char string[50];
    int flag, count = 0;

    cout << "The grammar is: S->aS, S->Sb, S->ab\n";
    cout << "Enter the string to be checked:\n";
    cin.getline(string, sizeof(string));

    if(string[0] == 'a')
    {
        flag = 0;
        for (count = 1; string[count - 1] != '\0'; count++)
        {
            if (string[count] == 'b')
            {
                flag = 1;
                continue;
            }
            else if ((flag == 1) && (string[count] == 'a'))
            {
                cout << "The string does not belong to the specified  grammar" << endl;
                break;
            }
            else if (string[count] == 'a')
            {
                continue;
            }
            else if ((flag == 1) && (string[count] == '\0'))
            {
                cout << "String accepted..!!!!" << endl;
                break;
            }
            else
            {
                cout << "String not accepted" << endl;
            }
        }
    }

     return 0;
}