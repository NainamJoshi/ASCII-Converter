#include <string>
using namespace std;
int encode(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        int temp = (int)str[i];
        cout << temp;
    }
    getchar();
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
    getchar();
}
int main()
{
    string str;
    cout << "Enter a string you want to encode or decode : " << endl;
    getline( cin , str );
    int val;
    cout << "Press 1 if you want to encode \nPress 2 if want to decode" << endl;
    cin>>val;
    switch (val)
    {
        case 1:
            encode (str);
            break;
        case 2:
            decode (str);
            break;
        default:
            cout << "Enter valid string without extra spaces" ;
            break;
    }
    getch();
}