// 1006 Fibonacci again and again 
#include<iostream>
#include<string>
using namespace std;
string cipher(string &s);
int main()
{
    string s1, s2, s3;
    while (1)
    {
        getline(cin, s1);
        if (s1 == "ENDOFINPUT")
            break;
        getline(cin, s2);
        getline(cin, s3);
        s1 = cipher(s2);
        cout <<s1<< endl;
    }
    return 0;
}
string cipher(string &s)
{
    char *p = new char[s.size() + 1];
    p[s.size()] = 0;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] <= 'E'&&s[i] >= 'A')
            p[i] = s[i] + 21;
        else if ('E' < s[i] && s[i] <= 'Z')
            p[i] = s[i] - 5;
        else
            p[i] = s[i];
    }
    string s1(p);
    delete[]p;
    return s1;
}

