#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

vector<vector<char>>v;
vector<string>path;

int st_r, en_r, st_c, en_c;
string str = "IEHOVA#";

int x[3]{ -1,0,0 };
int y[3]{ 0,1,-1 };
string dir[]{"forth","right","left"};


bool valid(int& r, int& c)
{
    if (r >= 0 && c >= 0 && r < (int)v.size() && c < (int)v[0].size())
        return true;
    return false;
}
void dfs(int r = st_r, int c = st_c,int idx=0)
{
    if (r == en_r && c == en_c)
        return;
    for (int i = 0;i < 3;i++)
    {
        int new_r=r + x[i];
        int new_c=c + y[i];
        if(valid(new_r,new_c)&&v[new_r][new_c]==str[idx])
        {
            path.push_back(dir[i]);
            dfs(new_r,new_c,idx+1);
        }
    }
}
int main()
{
    fastIO();
    //freopen(".in", "rt", stdin);
    //freopen(".out", "wt", stdout);
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        v = vector<vector<char>>(n, vector<char>(m));
        path = vector<string>(0);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                cin >> v[i][j];
                if (v[i][j] == '@')
                    st_r = i, st_c = j;
                else if (v[i][j] == '#')
                    en_r = i, en_c = j;
            }
        dfs();
        cout<<path[0];
        for(int i=1;i<(int)path.size();i++)
            cout<<" "<<path[i];
        cout<<"\n";
    }
    return 0;
}
