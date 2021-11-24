#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int arr[1000];
int main()
{
    fastIO();
	int n,m,q,min_diff,closest_sum,k=1;
	while(cin>>n,n!=0)
    {
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Case "<<k++<<":\n";
        cin>>m;
        while(m--)
        {
            cin>>q;
            closest_sum=arr[0]+arr[1];
            min_diff=abs(q-closest_sum);
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                {
                    if(abs(q-(arr[i]+arr[j]))<min_diff)
                    {
                        closest_sum=arr[i]+arr[j];
                        min_diff=abs(q-closest_sum);
                    }
                }
            cout<<"Closest sum to "<<q<<" is "<<closest_sum<<".\n";
        }
    }
    return 0;
}
