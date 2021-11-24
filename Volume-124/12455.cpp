#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int main()
{
    fastIO();
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        bool found=false;
        cin>>n>>p;
        int arr[p];
        for(int i=0;i<p;i++)
            cin>>arr[i];
        for(int mask=0;mask<(1<<p);mask++)
        {
            int sum=0;
            for(int i=0;i<p;i++)
                if(mask&(1<<i))
                    sum+=arr[i];
            if(sum==n)
            {
                found=true;
                break;
            }
        }
        if(found)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
