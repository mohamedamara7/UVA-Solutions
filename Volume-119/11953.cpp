#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int n;
vector<string>v;
vector<vector<int>>visited;

int x[4]{1,-1,0,0};
int y[4]{0,0,1,-1};

bool valid(int& r, int& c)
{
    if (r >= 0 && c >= 0 && r < (int)v.size() && c < (int)v[0].size())
        return true;
    return false;
}

void dfs(int r,int c)
{
    if(!valid(r,c)||visited[r][c]||v[r][c]=='.')
        return;
    visited[r][c]=1;
    for(int i=0;i<4;i++)
        dfs(r+x[i],c+y[i]);
}

int cntConnected()
{
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(v[i][j]=='x'&&!visited[i][j])
            {
                cnt++;
                dfs(i,j);
            }
    return cnt;
}
int main()
{
    fastIO();
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
	int t,i=1;
	cin>>t;
	while(t--)
    {
        cin>>n;
        v=vector<string>(n);
        visited=vector<vector<int>>(n,vector<int>(n));
        for(int i=0;i<n;i++)
            cin>>v[i];
        cout<<"Case "<<i++<<": "<<cntConnected()<<'\n';
    }
    return 0;
}
