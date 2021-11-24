#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

string conv_rec(int i)
{
    if(i==0)
        return "";
    return conv_rec(i/10)+char(i%10+'0');
}
string convert(int i)
{
    string str=conv_rec(i);
    for(i=0;i<5-str.size();i++)
        str='0'+str;
    return str;
}
int main()
{
    fastIO();
    int n;
    while(cin>>n,n!=0)
    {
        int sol=false;
        for(int i=1234;i<=98765/n;i++)
        {
            int j=n*i;
            int tmp, used =  (i < 10000); // if digit f=0, then we have to flag it
            tmp = j; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            tmp = i; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            if (used == (1<<10) - 1)
            {
                sol=true;
                cout<<convert(j)<<" / "<<convert(i)<<" = "<<n<<endl;
            }
        }
        if(!sol)
            cout<<"There are no solutions for "<<n<<"."<<endl;
        cout<<endl;
    }
    return 0;
}
