#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main()
{
    int n,m,i,j,u,v;
    cin>>n>>m;
    bool getin[n+1] = {false};
    vector<vector<int>> adj(n+1);
    queue<int>todo;
    int indegree[n+1] = {0};

    for(i=0;i<=m-1;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    for(i=1;i<=n;i++)
    {
        //cout<<"indegree:"<<indegree[i];
    }


    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            todo.push(i);
            getin[i] = true;
        }
    }

    while(todo.size()!=0)
    {

        u = todo.front();
        //cout<<"u"<<u<<" ";
        getin[u] = true;
        todo.pop();
        /*while(!adj[u].empty())
        {
            j = adj[u].end();
            todo.push(j);
            adj.pop_back();
        }*/
        for(auto &i : adj[u])
        {
            //cout<<"i:"<<i;
            indegree[i]--;
            //todo.push(adj[u][i]);
            if(indegree[i] ==0)todo.push(i);
        }
        adj[u].clear();
    }

    bool dag = true;
    for(int i=1;i<=n;i++)
    {
        if(!getin[i])
        {
            dag=false;
        }
    }

    if(dag)
    {
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
