#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int main()
{
    fastIO();
    int t,d,n,x,y,rats;
    int arr[1025][1025];
    cin>>t;
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        cin>>d>>n;
        while(n--)
        {
            cin>>x>>y>>rats;
            for(int i=x-d;i<=x+d;i++)
                if(i>=0&&i<1025)
                {
                    for(int j=y-d;j<=y+d;j++)
                        if(j>=0&&j<1025)
                            arr[i][j]+=rats;
                }
        }
        int max_i=0,max_j=0,max_rats=arr[0][0];
        for(int i=0;i<1025;i++)
            for(int j=0;j<1025;j++)
                if(arr[i][j]>max_rats)
                    max_rats=arr[i][j],max_i=i,max_j=j;
        cout<<max_i<<" "<<max_j<<" "<<max_rats<<endl;
    }
    return 0;
}
