#include <bits/stdc++.h>
using namespace std;
string s;
long long hashing(string s)
{
    long long hashCode = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hashCode += s[i]*(i + 1)*(i + 1);
    }
    return hashCode;
}
int main()
{
    getline(cin, s);
    cout<<hashing(s);
    return 0;
}
