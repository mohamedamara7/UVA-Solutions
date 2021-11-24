#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

//This is o(n!*n^2) solution n^2 is due to the safe function which we can get rid of it by using 3 arrays.
vector<int>sol(8);
int k=1;

bool safe(int r,int c)
{
    for(int cur_col=0;cur_col<c;cur_col++)
    {
        if(sol[cur_col]==r||abs(sol[cur_col]-r)==abs(c-cur_col))
            return false;
    }
    return true;
}
void n_queen(int int_r,int int_c,int col=0)
{
    if(col==8)
    {
        if(k<=9)
            cout<<" ";
        cout<<k++<<"     ";
        for(int i=0;i<8;i++)
            cout<<" "<<sol[i]+1;
        cout<<endl;
        return;
    }
    if(col==int_c)
    {
        if(safe(int_r,int_c))
        {
            sol[col]=int_r;
            n_queen(int_r,int_c,col+1);
        }
        return;
    }
    else
    {
        for(int i=0;i<8;i++)
        {
            if(safe(i,col))
            {
                sol[col]=i;
                n_queen(int_r,int_c,col+1);
            }
        }
    }
}
int main()
{
    fastIO();
    int t,int_r,int_c;
    cin>>t;
    while(t--)
    {
        cin>>int_r>>int_c;
        int_r--,int_c--;
        k=1;
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n";
        n_queen(int_r,int_c);
        if(t!=0)
            cout<<endl;
    }
    return 0;
}
