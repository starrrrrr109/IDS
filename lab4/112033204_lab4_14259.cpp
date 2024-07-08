#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
const int A = 998244353;
const int B = 1000000009;
const int N = 1000005;

int power[N];
vector<int>hsh(N);

int gethsh(int i,int j)
{
    if(i==0){
        return hsh[j];
    }else{
        return ((hsh[j] - 1LL * hsh[i - 1] * power[j - i + 1]) % B + B) % B;
    }
}
int main()
{
    int n,q,i,j,num1,num2;

    power[0]=1;
    for(i=1;i<=N;i++)
    {
        power[i] = 1LL*A*power[i-1] % B;
    }
    string str;
    cin>>str;
    n=str.length();
    vector<int>ans;
    hsh[0] = str[0];
    for(i=1;i<=n-1;i++)
    {
        hsh[i] = (1LL*hsh[i-1]*A+str[i])%B;
    }
    for(i=1;i<=n-1;i++)
    {
        if(gethsh(0,i-1) == gethsh(n-i,n-1))
        {
            ans.push_back(i);
        }
    }

    for(i = 0;i<=ans.size()-2;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[ans.size()-1];
    cout<<endl;
    return 0;
}
