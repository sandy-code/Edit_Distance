#include <iostream>
using namespace std;

int min(int x,int y, int z)
{
    return min(min(x,y),z);
}

int edit_dist(char a[], char b[], int m, int n)
{
    int l[m+1][n+1];
    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=n;j++)
        {
            if (i==0)
                l[i][j] = j;
            else if (j==0)
                l[i][j] = i;
            else if (a[i] == b[j])
                l[i][j] = l[i-1][j-1];
            else
                l[i][j] = 1 + min(l[i-1][j],l[i][j-1],l[i-1][j-1]);
        }
    }
    return l[m][n];
}

int main() {
	//code
	int t;
	cin>>t;
	while (t>0)
	{
	    int p,q;
	    cin>>p>>q;
	    char a[p], b[q];
	    cin>>a>>b;
	    int dist = edit_dist(a,b,p,q);
	    cout<<dist;
	    t--;
	}
	return 0;
}
