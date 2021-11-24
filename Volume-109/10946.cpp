#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int dir_r[]{-1,0,1,0};
int dir_c[]{0,1,0,-1};
int cnt;
struct cmp
{
    bool operator() (const pair<char,int> &l,const pair<char,int> &r)
    {
        if(l.second!=r.second)
            return l.second>r.second;
        return l.first<r.first;
    }
};
vector<string>mp;
vector<vector<bool>>visited;

bool inside(int i,int j)
{
    if(i>=0&&i<mp.size()&&j>=0&&j<mp[0].size())
        return true;
    return false;
}
void dfs(int i,int j,char c)
{
    if(visited[i][j]||mp[i][j]!=c)
        return;
    cnt++;
    visited[i][j]=1;
    for(int dir=0;dir<4;dir++)
    {
        int new_i=i+dir_r[dir];
        int new_j=j+dir_c[dir];
        if(inside(new_i,new_j))
            dfs(new_i,new_j,c);
    }
}
int main()
{
    fastIO();
    int x,y,num=0;
    while(cin>>x>>y,(x!=0&&y!=0))
    {
        mp=vector<string>(x);
        visited=vector<vector<bool>>(x,vector<bool>(y));
        multiset<pair<char,int>,cmp>ms;
        for(int i=0;i<x;i++)
            cin>>mp[i];
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
            {
                if(!visited[i][j]&&mp[i][j]!='.')
                {
                    cnt=0;
                    dfs(i,j,mp[i][j]);
                    ms.insert({mp[i][j],cnt});
                }
            }
        multiset<pair<char,int>,cmp>::iterator it=ms.begin();
        cout<<"Problem "<<++num<<":\n";
        for(;it!=ms.end();it++)
            cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
