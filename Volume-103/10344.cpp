#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;


vector<int>v(5);
bool solve(int result,int i=1)
{
    if(i==5)
    {
        if(result==23)
            return true;
        return false;
    }
    return solve(result+v[i],i+1)||solve(result-v[i],i+1)||solve(result*v[i],i+1);
}

int main()
{
    fastIO();
    while (true)
    {
        for (int i = 0;i < 5;i++)
            cin >> v[i];
        if (!v[0])
            return 0;
        bool possible=false;
        sort(v.begin(),v.end());
        do
        {
            if(solve(v[0]))
            {
                possible=true;
                cout<<"Possible\n";
                break;
            }
        }while(next_permutation(v.begin(),v.end()));
        if(!possible)
            cout<<"Impossible\n";
    }
    return 0;
}
