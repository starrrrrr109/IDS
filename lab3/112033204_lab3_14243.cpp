#include<iostream>
#include<cstring>
#include<vector>


using namespace std;

int main()
{
    int n,m,q,i,j,num1,num2,degree;
    cin>>n>>m>>q;
    vector<vector<bool>>adjecent(n,vector<bool>(n));
    vector<int>deg(n);

    for(i=0;i<=m-1;i++)
    {
        cin>>num1;
        cin>>num2;
        adjecent[num1-1][num2-1]=1;
        adjecent[num2-1][num1-1]=1;
        deg[num1-1]++;deg[num2-1]++;
    }

    char cmd;

    for(i=0;i<=q-1;i++)
    {

        //neighbor=0;
        cin>>cmd;
        if(cmd =='D')
        {
            cin>>num1;

            cout<<deg[num1-1]<<endl;
        }else
        if(cmd =='N')
        {
            cin>>num1;
            cin>>num2;
            if(adjecent[num1-1][num2-1]==1)
            {
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }
    return 0;
}
