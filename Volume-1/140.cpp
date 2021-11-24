#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int main()
{
    fastIO();
    string temp1;
    while(cin>>temp1,temp1[0]!='#')
    {
        string str="";
        bool mp[26][26];
        memset(mp,0,sizeof(mp));
        for(int i=0;i<temp1.size();)
        {
            if(str.find(temp1[i])==string::npos)
                str+=temp1[i];
            int j=i+2;
            for(;j<temp1.size()&&temp1[j]!=';';j++)
            {
                mp[temp1[i]-'A'][temp1[j]-'A']=1;
                mp[temp1[j]-'A'][temp1[i]-'A']=1;
                if(str.find(temp1[j])==string::npos)
                    str+=temp1[j];
            }
            i=j+1;
        }
        map<char,int> pos;
        sort(str.begin(),str.end());
        int mn_ord=INT_MAX;
        string res;
        do
        {
            for(int i=0;i<str.size();i++)
                pos[str[i]]=i;
            int cur_ord=INT_MIN;
            for(int i=0;i<str.size();i++)
            {
                int band_node=INT_MIN;
                for(int j=1;j<26;j++)
                    if(mp[str[i]-'A'][j])
                        band_node=max(band_node,abs(pos[str[i]]-pos[j+'A']));
                cur_ord=max(cur_ord,band_node);
            }
            if(cur_ord<mn_ord)
            {
                mn_ord=cur_ord;
                res=str;
            }
        }while(next_permutation(str.begin(),str.end()));
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<"-> "<<mn_ord<<endl;
    }
    return 0;
}
