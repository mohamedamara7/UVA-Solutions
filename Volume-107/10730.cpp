#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int arr[10000],mp[10000];
int main()
{
    fastIO();
	int n,temp;
	bool flag;
	char dummy;
	while(cin>>n,n!=0)
    {
        cin>>dummy;
        flag=false;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            mp[arr[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                temp=2*arr[j]-arr[i];
                if(temp>=0&&temp<n)
                {
                    if(mp[temp]>j)
                    {
                        flag=true;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
    return 0;
}
