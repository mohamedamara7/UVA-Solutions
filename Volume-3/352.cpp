#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

vector<string> v;
vector<vector<bool>>visited;
int x[8]{1,-1,0,0,1,1,-1,1};
int y[8]{0,0,1,-1,1,-1,1,-1};
bool valid(int &r,int &c)
{
    if(r>=0&&c>=0&&r<v.size()&&c<v.size())
        return true;
    return false;
}

void connected(int r,int c)
{
    if(!valid(r,c)||v[r][c]=='0'||visited[r][c])
        return;

    visited[r][c]=1;

    for(int i=0;i<8;i++)
    {
        connected(r+x[i],c+y[i]);
    }
}

int cntConnected()
{
    int cnt=0;
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v.size();j++)
            if (v[i][j]=='1'&&!visited[i][j])
            {
                cnt++;
                connected(i,j);
            }
    return cnt;
}
int main()
{
    fastIO();
	//freopen("Bumble.in", "rt", stdin);
	//freopen("Bumble.out", "wt", stdout);
    int n,num=1;
    while(cin>>n)
    {
        v=vector<string>(n);
        visited=vector<vector<bool>>(n,vector<bool>(n));
        for(int i=0;i<n;i++)
            cin>>v[i];
        cout<<"Image number "<<num++<<" contains "<<cntConnected()<<" war eagles.\n";
    }
    return 0;
}
