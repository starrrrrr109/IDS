#include<iostream>
#include<queue>

using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>> minheap;

    int i,x,n,cmd;
    cin>>n;
    while(n--)
    {
        cin>>cmd;
        if(cmd==1)
        {
            cin>>x;
            minheap.push(x);
        }
        if(cmd==2)
        {
            if(!minheap.empty())
            {
                minheap.pop();
            }
        }
        if(cmd==3)
        {
            if(!minheap.empty())
            {
                x = minheap.top();
                cout<<x<<endl;
            }else{
                cout<<"EMPTY"<<endl;
            }
        }
    }

    return 0;
}


