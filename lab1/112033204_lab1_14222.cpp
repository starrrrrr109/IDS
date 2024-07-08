#include<iostream>

using namespace std;

int main()
{
    long long n,m,mid,temp,i,j,l,r;
    cin>>n>>m;

    long long a[n],q[m];

    for(i=0;i<=n-1;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<=m-1;i++)
    {
        cin>>q[i];
    }

    for(i=0;i<=m-1;i++)//search
    {
        l=0;r=n-1;
        int found=0;
        while(r>=l)
        {
            mid = (l+r)/2;
            //cout<<"mid ="<<mid<<endl;
            if(a[mid]==q[i])
            {
                cout<<"Y ";
                found=1;
                break;
            }else
            if(q[i]<a[mid]){
                l=mid+1;
            }else
            if(q[i]>a[mid])
            {
                r=mid-1;
            }
        }
        if(found==0)cout<<"N ";

    }
    //for(i=0;i<=n-1;i++)cout<<a[i]<<endl;



    return 0;


}
