#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

vector<int>sol;
int cnt;
bool safe(int r,int c)
{
    for(int cur_col=0;cur_col<c;cur_col++)
    {
        if(sol[cur_col]==r||abs(sol[cur_col]-r)==abs(c-cur_col))
            return false;
    }
    return true;
}
void n_queen(int n,int col=0)
{
    if(col==n)
    {
        cnt++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if((bad.find(col)==bad.end()||bad[col]!=i)&&safe(i,col))
        {
            sol[col]=i;
            n_queen(n,col+1);
        }
    }
}
int main()
{
    fastIO();
    int n,k=1;
    char x;
    while(cin>>n,n!=0)
    {
        sol=vector<int>(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin>>x;
                if(x=='*')
                    bad.insert({j,i});
            }
        cnt=0;
        n_queen(n);
        cout<<"Case "<<k++<<": "<<cnt<<endl;
    }
    return 0;
}
