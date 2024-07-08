#include<iostream>
#include<vector>

using namespace std;

void merge();
//merge two sorted array

void merge_sort(vector<long long>&arr,int l,int r);
//divide and conquer

int main() {
    int n,i;
    long long num;
    cin>>n;

    vector<long long>arr;
    for(i=0;i<=n-1;i++)
    {
        cin>>num;
        arr.push_back(num);
    }

    merge_sort(arr,0,n-1);

    for(auto it = arr.begin();it!=arr.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}

void merge(vector<long long> &arr,int l,int r)
{
    int m = (l+r)/2;
    vector<long long>temp;
    int i=l,j=m+1;

    /*cout<<"the left: ";
    for(i = l;i<=m;i++)cout<<arr[i]<<" ";
    cout<<"the right: ";
    for(i = m+1;i<=r;i++)cout<<arr[i]<<" ";
    cout<<endl;
    i=l,j=m+1;*/
    while(i<=m && j<=r)
    {
        if(arr[i]>=arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=m){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(arr[j]);
        j++;
    }


    //cout<<"and now ";
    for(i=0;i<=temp.size()-1;i++)
    {
        arr[l+i] = temp[i];
        //cout<<arr[l+i]<<" ";
    }
    //cout<<"is complete"<<endl;
}


void merge_sort(vector<long long> &arr,int l,int r)
{
    if(l==r)return;
    int m=(l+r)/2;
    //cout<<"l: "<<l<<" m:"<<m<<" r: "<<r<<endl;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr,l,r);

}
