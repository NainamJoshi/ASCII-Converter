#include <iostream>
#include <string>
using namespace std;

void encode(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        int temp = (int)str[i];
        cout << temp;
    }
    cout << endl;
}

void decode(string str)
{
    int len = str.length();
    int num = 0;
    for (int i = 0; i < len; i++) 
    {
        num = num * 10 + (str[i] - '0');
        if (num >= 32 && num <= 122) 
        {
            char ch = (char)num;
            cout << ch;
            num = 0;
        }
    }
    cout << endl;
}

int main()
{
    string str;
    int val;

    cout << "Enter a string you want to encode or decode: ";
    getline(cin, str);

    cout << "Press 1 to Encode\nPress 2 to Decode: ";
    cin >> val;
    cin.ignore(); // Clear the newline left in buffer

    switch (val)
    {
        case 1:
            encode(str);
            break;
        case 2:
            decode(str);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}
