#include<iostream>
#include<cstring>
#include<vector>


using namespace std;

int main()
{
    int n,m,q,i,j,num1,num2;
    cin>>n>>m>>q;
    vector<vector<bool>>adjecent(n);

    for(i=0;i<=m-1;i++)
    {
        cin>>num1;
        cin>>num2;
        adjecent[num1-1].push_back(num2);
        adjecent[num2-1].push_back(num1);
    }

    char cmd;

    for(i=0;i<=q-1;i++)
    {

        //neighbor=0;
        cin>>cmd;
        if(cmd =='D')
        {
            cin>>num1;
            cout<<adjecent[num1-1].size()<<endl;

        }else
        if(cmd =='N')
        {
            bool found=0;
            cin>>num1;
            cin>>num2;
            for(auto it = adjecent[num1-1].begin();it!=adjecent[num1-1].end();it++)
            {
                if(*it == num2)found =1;
            }
            if(found==1){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }
    return 0;
}
