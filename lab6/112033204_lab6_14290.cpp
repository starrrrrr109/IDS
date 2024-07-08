#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>

using namespace std;

string trans(string in)
{
    map<char,int>priority{
        {'+',1},{'-',1},{'*',2},{'/',2}
    };
    stack<char> opestack;
    string post;
    for(auto i : in)
    {
        if(i>='A'&&i<='Z')
        {
            post.push_back(i);
        }else
        if(i == '+' || i == '-' || i == '*' || i == '/')
        {
            while(opestack.size()!=0 && priority[opestack.top()]>=priority[i] && opestack.top() != '(')
            {
                post.push_back(opestack.top());
                opestack.pop();
            }
            opestack.push(i);
        }else
        if(i=='('){
            opestack.push(i);
        }
        if(i==')'){
            while(opestack.top()!='(' && !opestack.empty())
            {
                post.push_back(opestack.top());
                opestack.pop();
            }
            opestack.pop();
        }
    }
    while(!opestack.empty())
    {
        post.push_back(opestack.top());
        opestack.pop();
    }

    return post;
}
void calculate(string post,int n)
{
    int num[5];
    int j,ans;
    stack<int> cal;
    for(j=0;j<=4;j++)
    {
        cin>>num[j];
    }
    for(auto i : post)
    {
        if(i>='A' && i<='Z'){
            cal.push(num[i-'A']);
        }else
        if(i == '+')
        {
            int b = cal.top();
            cal.pop();
            int a = cal.top();
            cal.pop();
            ans = a+b;
            cal.push(ans);
        }
        if(i == '-')
        {
            int b = cal.top();
            cal.pop();
            int a = cal.top();
            cal.pop();
            ans = a-b;
            cal.push(ans);
        }
        if(i == '*')
        {
            int b = cal.top();
            cal.pop();
            int a = cal.top();
            cal.pop();
            ans = a*b;
            cal.push(ans);
        }
        if(i == '/')
        {
            int b = cal.top();
            cal.pop();
            int a = cal.top();
            cal.pop();
            ans = a/b;
            cal.push(ans);
        }
    }
    cout<<cal.top();
    if(n>1)cout<<'\n';
}
int main()
{
    string str;
    int i,j,n;
    cin>>str;
    string post = trans(str);
    //cout<<post;
    cin>>n;
    while(n!=0)
    {
        calculate(post,n);
        n--;
    }

    return 0;
}
