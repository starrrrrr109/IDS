#include<iostream>
#include<vector>
using namespace std;

vector<int> Father,Size;
int maxsize=1,component;

int find(int x) {
	if (x == Father[x])return x;
	else return Father[x] = find(Father[x]);

}

void unite(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	if(rooty==rootx)return ;
	if(Size[rootx]>Size[rooty])swap(rootx,rooty);
	Father[rootx] = rooty;
	component--;
	Size[rooty]+=Size[rootx];
	if (Size[rooty] > maxsize)maxsize = Size[rooty];
}

int main() {
	int n,m,i,v1,v2;
	cin>>n>>m;
	component = n;
	for(i=0;i<=n;i++)
    {
        Father.push_back(i);
        Size.push_back(1);
    }
    while(m--)
    {
        cin>>v1>>v2;
        unite(v1,v2);
        cout<<component<<" "<<maxsize<<endl;
    }
    return 0;
}
