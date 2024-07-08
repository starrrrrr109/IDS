#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;
const int A = 998244353;
const int B = 1000000009;
const int N = 2E5 + 5;

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
    int n,m,i,j,num1,num2;


    string needle,haystack;
    cin>>needle>>haystack;
    n = needle.length();m = haystack.length();
    array<int,26>nalpha = {};
    vector<array<int,26>>halpha(m-n+1);
    vector<int>arrangement;

    power[0]=1;
    for(i=1;i<=N;i++)
    {
        power[i] = 1LL*A*power[i-1] % B;
    }
    hsh[0] = haystack[0];
    for(i=1;i<=n-1;i++)
    {
        hsh[i] = (1LL*hsh[i-1]*A+haystack[i])%B;
    }


    for(i=0;i<=n-1;i++)                     //統計N字母
    {
        //cout<<needle[i]-'a'<<" " ;
        nalpha[needle[i]-'a']++;
    }
    //cout<<endl;
    for(i=0;i<=m-n;i++)                     //統計H字母
    {
        for(j=0;j<=n-1;j++)
        {
            halpha[i][haystack[i+j]-'a']++;
            //cout<<haystack[i+j]-'a'<<" " ;
        }
    }
    //cout<<endl;
    for(i=0;i<=m-n;i++)
    {
        int match=1;
        for(j=0;j<=n-1;j++)
        {
            if(nalpha[j] != halpha[i][j])match=0;
        }
        if(match==1)
        {
            arrangement.push_back(gethsh(i,i+n-1));
            //cout<<"match";
        }
    }

    sort(arrangement.begin(),arrangement.end());
    for(auto x:arrangement)
        {
        //cout<<x<<" ";
    }
    int Count=1;

    for(i=1;i<=arrangement.size()-1;i++)
    {
        if(arrangement[i]!=arrangement[i-1])Count++;
    }
    cout << Count<<endl;
    return 0;
}
