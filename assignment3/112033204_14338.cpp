#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int countloli(int n,int hp,vector<int>& power,vector<int>& brave)
{
    vector<pair<int,int>>loli;
    for(int i=0;i<=n-1;i++)
    {
        loli.emplace_back(power[i],brave[i]);
    }

    sort(loli.begin(),loli.end(),[](const pair<int,int>a,const pair<int,int>b)
    {
        return a.second>b.second;
    });

    /*for(auto it:loli)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }*/

    int damage=0,lolinumber=0;
    for(auto it:loli)
    {
        if(hp<=it.second)
        {
            hp-=it.first;
            lolinumber++;
            //damage+=it.first;
        }
        if(hp<=0)break;
    }

    if(hp<=0){
        return lolinumber;
    }else{
        return -1;
    }
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int>m(N),c(N);
    for(int i=0;i<=N-1;i++)
    {
        cin>>m[i];
        cin>>c[i];
    }

    cout<<countloli(N,M,m,c)<<'\n';
}
