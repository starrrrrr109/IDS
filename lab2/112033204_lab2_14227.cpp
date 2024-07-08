#include<iostream>
#include<vector>
#include<cstring>

using namespace std;


int judge(string bracket)
{
    int i;
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
                }else{
                    return 0;
                }
            }
            if(bracket[i] ==']')
            {
                if(STACK[STACK.size()-1] == '[')
                {
                    STACK.pop_back();
                }else{
                    return 0;
                }
            }
            if(bracket[i] ==')')
            {
                if(STACK[STACK.size()-1] == '(')
                {
                    STACK.pop_back();
                }else{
                    return 0;
                }
            }

        }
    }
    if(STACK.size() == 0)
    {
        return 1;
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
        if(judge(bracket[i]) == 1)
        {
            cout<<"Y"<<endl;
        }else
        if(judge(bracket[i]) == 0)
        {
            cout<<"N"<<endl;
        }
    }

    if(judge(bracket[n-1]) == 1)
        {
            cout<<"Y";
        }else
        if(judge(bracket[i]) == 0)
        {
            cout<<"N";
        }

    return 0;
}
