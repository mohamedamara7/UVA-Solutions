#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int arr[20];
int main()
{
    fastIO();
    long long t,d,k,res,pw,n;
    string str_n,dummy;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n++;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>d>>k;
        int i=ceil((-1.0+sqrt(1+(8.0*k/d)))/2.0);
        res=0,pw=1;
        for(int k=0;k<n;k++)
        {
            res+=arr[k]*pw;
            pw*=i;
        }
        cout<<res<<endl;
    }
    return 0;
}
