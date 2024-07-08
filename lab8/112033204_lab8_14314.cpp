#include<iostream>
#include<set>
#include<vector>
#include<map>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,j,x,s;
    char cmd;
    cin>>n;
    map<int,int>mp;
    for(i=0;i<=n-1;i++)
    {
        cin>>cmd>>x;
        if(cmd=='I')
        {
            auto it = mp.find(x);
            if(it==mp.end())
            {
                mp[x]++;
            }
            cout<<mp.size()<<"\n";
        }
        if(cmd=='D')
        {
            auto it = mp.find(x);
            if(it!=mp.end())
            {
                mp[x]--;
                if(mp[x]==0)mp.erase(x);
            }
            cout<<mp.size()<<"\n";
        }
        if(cmd=='S')
        {
            auto it = mp.find(x);
            if(it!=mp.end())
            {
                cout<<"YES"<<endl;
            }else
            {
                cout<<"NO"<<endl;
            }
        }
        if(cmd=='L') //find lower bound
        {
            auto it = mp.lower_bound(x);
            if(it!=mp.end())
            {
                cout<<it->first<<endl;
            }else
            {
                cout<<"-1\n";
            }
        }
        if(cmd=='U')
        {
            auto it = mp.upper_bound(x);
            if(it!=mp.end())
            {
                cout<<it->first<<endl;
            }else
            {
                cout<<"-1\n";
            }
        }
    }
    return 0;
}
