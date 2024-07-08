#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using LL=long long int;

int main()
{
    int i,j,n,m,u,v1,v2,v3,num;
    char cmd;

    cin>>n>>m;
    vector<vector<LL>>adj(n+1);
    queue<int>q;
    LL value[n+1]={0};
    int indegree[n+1]={0};
    bool qef[n+1]={false};
    for(i=0;i<=m-1;i++)
    {
        cin>>cmd;
        if(cmd=='A')
        {
            cin>>u;
            cin>>num;
            value[u] = num;
        }
        if(cmd=='B')
        {
            cin>>u>>v1;
            cin>>num;
            value[u] = num;
            adj[v1].push_back(u);
            indegree[u]++;
        }
        if(cmd=='C')
        {
            cin>>u>>v1>>v2;
            cin>>num;
            value[u] = num;
            adj[v1].push_back(u);adj[v2].push_back(u);
            indegree[u]++;indegree[u]++;

        }
        if(cmd=='D')
        {
            cin>>u>>v1>>v2>>v3;
            cin>>num;
            value[u] = num;
            adj[v1].push_back(u);adj[v2].push_back(u);adj[v3].push_back(u);
            indegree[u]++;indegree[u]++;indegree[u]++;
        }
    }

    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            //cout<<"i: "<<i;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        i = q.front();
        qef[i] = true;
        for(auto &j : adj[i])
        {
            indegree[j]--;
            //cout<<"j "<<j<<endl;
            value[j]+=value[i];
            //cout<<"jvalue "<<value[j]<<endl;
            if(indegree[j]==0)
            {
                q.push(j);
            }
        }
        q.pop();
    }

    for(i=1;i<=n;i++)
    {
        if(qef[i])
        {
            cout<<value[i]<<'\n';
        }else
        {
            cout<<"#REF!\n";
        }
    }

}

