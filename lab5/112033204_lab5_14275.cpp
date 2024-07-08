#include<iostream>
#include<vector>
#include<queue>
using LL = long long int;

using namespace std;

void bfs(int i,vector<vector<int>> &adj,vector<bool> &found)
{
    found[i] = true;

    queue<int> q;

    q.push(i);
    //cout<<"size:"<<q.size()<<endl;
    while(q.size()!=0)
    {
        int num = q.front();
        for(auto it = adj[num].begin(); it != adj[num].end();it++)
        {
            if(found[*it]==false)q.push(*it);
        }
        q.pop();
        found[num] = true;
    }
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0);
    int t,i,j,v1,v2;
    cin>>t;
    int Count[t];
    for(i=0;i<=t-1;i++)
    {
        int n,m;
        cin>>n>>m;
        vector< vector<int>> adj(n);
        vector<bool> found(n,false);
        for(j=0;j<=m-1;j++)
        {
            cin>>v1;
            cin>>v2;
            v1--;v2--;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        Count[i] = 0;
        //cout<<"hello:";
        for(j=0;j<=n-1;j++)
        {
            //cout<<"hello:";
            if(!found[j]){
                bfs(j,adj,found);
                Count[i]++;
            }
        }
    }
    for(i=0;i<=t-2;i++)
    {
        cout<<Count[i]<<'\n';
    }
    cout<<Count[t-1];
    return 0;
}
