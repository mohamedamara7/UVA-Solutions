#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

double minimum;
vector<int> ans;
double calc_distances(vector<pair<int,int>>&positions,vector<int>&sel)
{
    double dist=0;
    for(int i=1;i<sel.size();i++)
    {
        double diff_x=positions[sel[i]].first-positions[sel[i-1]].first
        ,diff_y=positions[sel[i]].second-positions[sel[i-1]].second;

        dist+=sqrt(diff_x*diff_x+diff_y*diff_y)+16.0;
    }
    return dist;
}
void solve(vector<pair<int,int>>&positions,vector<int>sel,int cur_len)
{
    if(cur_len==positions.size())
    {
        double distances=calc_distances(positions,sel);
        if(distances<minimum)
        {
            minimum=distances;
            ans=sel;
        }
    }
    for(int i=0;i<positions.size();i++)
        if(find(sel.begin(),sel.begin()+cur_len,i)==sel.begin()+cur_len)
        {
            sel[cur_len]=i;
            solve(positions,sel,cur_len+1);
        }
}
int main()
{
    fastIO();
    int t,i=1;
    while(cin>>t,t>0)
    {
        minimum=INT_MAX;
        vector<pair<int,int>>positions(t);
        vector<int>sel(t);
        for(int i=0;i<t;i++)
            cin>>positions[i].first>>positions[i].second;
        solve(positions,sel,0);
        cout<<"**********************************************************\nNetwork #"<<i++<<"\n";
        cout<<fixed<<setprecision(2);
        for(int i=1;i<t;i++)
        {
            double diff_x=positions[ans[i]].first-positions[ans[i-1]].first
            ,diff_y=positions[ans[i]].second-positions[ans[i-1]].second;
            cout<<"Cable requirement to connect ("<<positions[ans[i-1]].first<<","<<positions[ans[i-1]].second
                <<") to ("<<positions[ans[i]].first<<","<<positions[ans[i]].second<<") is "
                <<sqrt(diff_x*diff_x+diff_y*diff_y)+16<<" feet.\n";
        }
        cout<<"Number of feet of cable required is "<<minimum<<".\n";
    }
    return 0;
}
