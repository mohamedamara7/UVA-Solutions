#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

/*
x>=y -> 1/x<=1/y. 1/x+1/y=1/k -> 1/y+1/y>=1/k -> 2/y>=1/k -> y<=2k.
x=k*y/(y-k) -> y can't be small than k as this will lead to a negative value, and can'y be zero. So, it should be greater than k.
*/
int main()
{
    fastIO();
    int k,cnt,y;
    while(cin>>k)
    {
        vector<pair<int,int>>v;
        for(int y=k+1;y<=2*k;y++)
        {
            if(k*y%(y-k)==0)
            v.push_back({k*y/(y-k),y});
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
            cout<<"1/"<<k<<" = "<<"1/"<<v[i].first<<" + "<<"1/"<<v[i].second<<endl;
    }
    return 0;
}
