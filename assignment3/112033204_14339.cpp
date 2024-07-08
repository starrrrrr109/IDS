#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef struct
{
    int v1,v2,cost;
}edge;
vector<int>parent;
vector<int>Size;
int distance(pair<int,int>a,pair<int,int>b)
{
    int dis = (a.first-b.first) * (a.first-b.first) + (a.second - b.second) * (a.second-b.second);
    //cout<<"dis: "<<dis<<endl;
    return dis;
}
bool compare(edge a,edge b)
{
    return a.cost<b.cost;
}

int find(int x)
{
    if(x == parent[x])return x;
    else return parent[x] = find(parent[x]);
}

bool unite(int x,int y)
{
    int rootx=find(x);int rooty =find(y);
    if (rootx == rooty)return false;
    else{
        if(Size[rootx] < Size[rooty])swap(rootx,rooty);
        parent[rooty] = rootx;
        Size[rootx] = Size[rootx] + Size[rooty];
        return true;
    }
}
int main()
{
    int N,x,y,ans=0,connect = 0;
    cin>>N;
    vector<pair<int,int>> point;
    vector<edge>edges;

    for(int i=0;i<=N-1;i++)
    {
        cin>>x>>y;
        point.emplace_back(x,y);
    }
    for(auto it:point)
    {
        //cout<<"a: "<<it.first;
    }
    for(int i=0;i<=N-1;i++)
    {
        for(int j=i+1;j<=N-1;j++)
        {
            edge s = {i,j,distance(point[i],point[j])};
            edges.push_back(s);
        }
    }

    sort(edges.begin(),edges.end(),compare);


    for(int i=0;i<=edges.size()-1;i++)
    {
        parent.push_back(i);
        Size.push_back(1);
    }
    for(auto it:edges)
    {

        if(unite(it.v1,it.v2))
        {
            //cout<<"v1:"<<it.v1<<"v2:"<<it.v2<<"cost:"<<it.cost<<endl;
            ans+=it.cost;
            connect++;
        }
        if(connect>=N-1)break;
    }

    cout<<ans<<'\n';
}
