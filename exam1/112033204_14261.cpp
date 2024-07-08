#include<iostream>
#include<vector>
#include<list>

using namespace std;

typedef struct node
{
    int last;
    int next;
}node;
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //cout<<"hello"<<endl;
    int N,Q,i,num,head,tail,pre,cmd,x,y,z;
    //vector<int>vec[20000];
    node L[200001];
    cin>>N;

    cin>>num;
    head=num;
    L[num].last = -1;
    pre = num;

    for(i=1;i<=N-1;i++)
    {
        cin>>num;
        L[num].last = pre;
        L[pre].next = num;
        pre = num;
    }
    L[num].next = -1;
    tail = num;

    cin>>Q;
    for(i=0;i<=Q-1;i++)
    {
        cin>>cmd;
        if(cmd==1) //insert y after x
        {
            cin>>x>>y;
            if(x!= tail)
            {
                z = L[x].next;
                L[y].last = x;
                L[y].next = z;
                L[x].next = y;
                L[z].last = y;
            }else
            if(x==tail)
            {
                L[y].last = x;
                L[x].next = y;
                L[y].next = -1;
                tail = y;
            }
        }else
        if(cmd==2) //rm x
        {
            cin>>x;
            if(x!=tail && x!=head)
            {
                y = L[x].last;
                z = L[x].next;
                L[y].next = z;
                L[z].last = y;
            }else
            if(x==tail)
            {
                y = L[x].last;
                L[y].next = -1;
                tail = y;
            }else
            if(x==head)
            {
                z = L[x].next;
                L[z].last = -1;
                head = z;
            }
        }
    }
    i=head;
    while(i!=tail)
    {
        cout<<i<<" ";
        i = L[i].next;
    }
    cout<<i;

    //vec[head][0]=-1;   //vec第一格存前面的數 第二格存後面的數

    /*for(i=1;i<=N-1;i++)
    {
        if(num1!=head){
            vec[num1][0] = pre;
        }
        cin>>num2;
        vec[num1][1]=num2;
        pre = num1;
        num1 = num2;
    }*/
    //vec[num1][0]=(pre);
    //vec[num1][1]=(-1);

    /*cin>>Q;
    for(i=0;i<=Q-1;i++)
    {
        cin>>cmd;
        if(cmd==1) //insert y after x
        {
            cin>>x>>y;
            if(vec[x][1]!=-1)
            {
                vec[y][0]=(x);
                vec[y][1]=(vec[x][1]);
                vec[x][1] = y;

            }else{          //x is the last one
                vec[x][1] = y;
                vec[y][0] = x;
                vec[y][1] = (-1);
            }
        }else
        if(cmd==2) //rm x
        {
            cin>>x;
            if(vec[x][0] == -1)  //第一個
            {
                head = vec[x][1];
                vec[x][1]=0;
                vec[x][0]=0;
                vec[head][0] = -1;
            }else
            if(vec[x][1] == -1)  //最後一個
            {
                vec[vec[x][0]][1] = -1;
                vec[x][0]=0;
                vec[x][1]=0;
            }else{//中間
                vec[vec[x][0]][1] = vec[x][1];
                vec[vec[x][1]][0] = vec[x][0];
                vec[x][1]=0;
                vec[x][1]=0;
            }
        }
    }*/

    /*int t=head;
    while(vec[t][1]!=-1)
    {
        cout<<t<<" ";
        t = vec[t][1];
    }
    cout<<t;*/
    return 0;
}
