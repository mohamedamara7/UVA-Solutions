#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

vector<int>sol(8),sel(8);

int k=1;

bool safe(int r,int c)
{
    for(int cur_col=0;cur_col<c;cur_col++)
    {
        if(abs(sol[sel[cur_col]]-sol[r])==abs(c-cur_col))
            return false;
    }
    return true;
}
void n_queen(int cur_len,int int_r,int int_c)
{
    if(cur_len==8)
    {
        if(sol[sel[int_c]]==int_r)
        {
            if(k<=9)
                cout<<" ";
            cout<<k++<<"     ";
            for(int i=0;i<8;i++)
                cout<<" "<<sol[sel[i]];
            cout<<endl;
        }
        return;
    }
    for(int i=0;i<8;i++)
    {
        if(find(sel.begin(),sel.begin()+cur_len,i)==sel.begin()+cur_len)
        {
            if(safe(i,cur_len))
            {
                sel[cur_len]=i;
                n_queen(cur_len+1,int_r,int_c);
            }
        }
    }

}
int main()
{
    fastIO();
    int t,int_r,int_c;
    sol={1,2,3,4,5,6,7,8};
    cin>>t;
    while(t--)
    {
        cin>>int_r>>int_c;
        int_c--;
        k=1;
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n";
        n_queen(0,int_r,int_c);
        if(t!=0)
            cout<<endl;
    }
    return 0;
}
