#include<iostream>
#include<vector>
#include<cstring>

using namespace std;


int judge(string bracket)
{
    int i,Count=0;
    vector<char> STACK;
    int length = bracket.length();
    for(i=0;i<=length-1;i++)
    {
        if(bracket[i] == '{'||bracket[i] == '['||bracket[i] == '(')
        {
            STACK.push_back(bracket[i]);
        }
        if(bracket[i] == '}'||bracket[i] == ']'||bracket[i] == ')')
        {
            if(STACK.size()==0)
            {
                return 0;
            }
            if(bracket[i] =='}')
            {
                if(STACK[STACK.size()-1] == '{')
                {
                    STACK.pop_back();
                    Count++;
                }else{
                    return 0;
                }
            }
            if(bracket[i] ==']')
            {
                if(STACK[STACK.size()-1] == '[')
                {
                    STACK.pop_back();
                    Count++;
                }else{
                    return 0;
                }
            }
            if(bracket[i] ==')')
            {
                if(STACK[STACK.size()-1] == '(')
                {
                    STACK.pop_back();
                    Count++;
                }else{
                    return 0;
                }
            }

        }
    }
    if(STACK.size() == 0)
    {
        return Count;
    }else{
        return 0;
    }
}
int main()
{
    int n,i;
    cin>>n;
    string bracket[n];

    for(i=0;i<=n-1;i++)
    {
        cin>>bracket[i];
    }
    for(i=0;i<=n-2;i++)
    {
        cout<<judge(bracket[i])<<'\n';
    }


    cout<<judge(bracket[i]);

    return 0;
}
