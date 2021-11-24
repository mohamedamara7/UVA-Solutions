#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

struct cons
{
    int a,b,c;
};
int main()
{
    fastIO();
    int n,m;
    while(cin>>n>>m,n+m!=0)
    {
        vector<int>group(n);
        vector<cons>constrains(m);
        for(int i=0;i<n;i++)
            group[i]=i;
        for(int i=0;i<m;i++)
            cin>>constrains[i].a>>constrains[i].b>>constrains[i].c;
        int cnt=0;
        do
        {
            bool sol=true;
            for(int i=0;i<m;i++)
            {
                int pos_a=find(group.begin(),group.end(),constrains[i].a)-group.begin(),pos_b=find(group.begin(),group.end(),constrains[i].b)-group.begin();
                if(constrains[i].c>0)
                {
                    if(abs(pos_a-pos_b)>constrains[i].c)
                    {
                      sol=false;
                      break;
                    }
                }
                else
                {
                    if(abs(pos_a-pos_b)<-constrains[i].c)
                    {
                      sol=false;
                      break;
                    }
                }
            }
            if(sol)
                cnt++;
        }while(next_permutation(group.begin(),group.end()));
        cout<<cnt<<endl;
    }
    return 0;
}
