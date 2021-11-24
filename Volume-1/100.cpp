#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int max_size=1000000;
vector<int> lens(max_size,-1);
int len_3n_1(int n)
{
    if(n==1)
        return 1;
    if(n<max_size&&lens[n]!=-1)
        return lens[n];
    if(n%2)
    {
        int len=1+len_3n_1(3*n+1);
        if(n<max_size)
            lens[n]=len;
        return len;
    }
    else
    {
        int len=1+len_3n_1(n/2);
        if(n<max_size)
            lens[n]=len;
        return len;
    }
}
int main()
{
    fastIO();
    int x,y;
    while(cin>>x>>y)
    {
        cout<<x<<" "<<y<<" ";
        if(x>y)
            swap(x,y);
        int mx_len=0;
        for(int i=x;i<=y;i++)
        {
            int len=len_3n_1(i);
            if(len>mx_len)
                mx_len=len;
        }
        cout<<mx_len<<endl;
    }
    return 0;
}
