#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int A = 1000000007;
const int B = 1000000009;
const int N = 5005;

int power[N];

int main()
{
    int n,q,i,j,num1,num2;

    power[0]=1;
    for(i=1;i<=5004;i++)
    {
        power[i] = 1LL*A*power[i-1] % B;
    }
    cin>>n>>q;
    char cmd;

    string str;
    vector<int>hsh(n);
    vector<int>sz(n);
    for(i=0;i<=n-1;i++)
    {
        cin>>str;
        sz[i] = str.size();
        for(j = 0;j<=str.size()-1;j++)
        {
            hsh[i] = (1LL*hsh[i]*A+str[j])%B;
        }
    }

    for(i=0;i<=q-1;i++)
    {
        cin>>cmd;
        if(cmd == 'E')
        {
            cin>>num1>>num2;
            if(hsh[num1-1] == hsh[num2-1]){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
        if(cmd == 'C')
        {
            cin>>num1>>num2;
            hsh[num1-1] = (1LL*hsh[num1-1]*A*power[sz[num2-1]]+hsh[num2-1])%B;
            sz[num1-1]+=sz[num2-1];
        }
    }

    return 0;
}
