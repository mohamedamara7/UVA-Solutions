#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

vector<vector<int>> board(8,vector<int>(8));
vector<int> queens(8);
int mx_cnt;

bool save(int c)
{
    int row=queens[c];
    for(int i=0;i<c;i++)
    {
        int diff=abs(row-queens[i]);
        if(diff==0||diff==c-i)
            return false;
    }
    return true;
}
void solve_8q(int c=0)
{
    if(c==8)
    {
        int cnt=0;
        for(int i=0;i<8;i++)
            cnt+=board[queens[i]][i];
        if(cnt>mx_cnt)
            mx_cnt=cnt;
        return;
    }
    for(int i=0;i<8;i++)
    {
        queens[c]=i;
        if(save(c))
            solve_8q(c+1);
    }
}
int main()
{
    fastIO();
    int t;
    cin>>t;
    while(t--)
    {
        mx_cnt=0;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                cin>>board[i][j];
        solve_8q();
        cout<<setw(5)<<right<<mx_cnt<<endl;
    }
    return 0;
}
