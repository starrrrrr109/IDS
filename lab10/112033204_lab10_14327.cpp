#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long int;

using namespace std;

vector<int> Father,Size;

typedef struct
{
    int u,v;
    ll cost;
}edge;

bool compare(edge edge1,edge edge2)
{
    return edge1.cost<edge2.cost;
}

int find(int x)
{
    if(Father[x] == x)return x;
    else return Father[x] = find(Father[x]);
}

bool unite(int x,int y)
{
    int rootx=find(x);
    int rooty=find(y);
    if(rootx==rooty)return false;
    if(Size[rootx]>Size[rooty])swap(rootx,rooty);
    Size[rooty]+=Size[rootx];
    Father[rootx] = rooty;
    return true;
}
int main()
{
    int i,n,m,v1,v2,w;
    ll ans=0;
    cin>>n>>m;
    vector<edge>edges;
    for(i=0;i<=n;i++)
    {
        Father.push_back(i);
        Size.push_back(1);
    }
    while(m--)
    {
        cin>>v1>>v2>>w;
        edge a={v1,v2,w};
        edges.push_back(a);
    }
    //for(auto it:edges)cout<<it.cost<<endl;
    sort(edges.begin(),edges.end(),compare);

    for(auto it:edges)
    {
        if(unite(it.u,it.v))ans+=it.cost;
    }

    cout<<ans<<"\n";
    return 0;

}
