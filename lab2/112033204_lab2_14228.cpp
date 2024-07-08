#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int n,i;
    cin>>n;
    queue<int> q;
    for(i=1;i<=n;i++)
    {
        q.push(i);
    }

    while(q.size()!=0)
    {
        i = q.front();
        q.pop();
        q.push(i);
        i = q.front();
        q.pop();
        if(q.size()!=0)
        {
            cout<<i<<" ";
        }else{
            cout<<i;
        }
    }

    return 0;
}
