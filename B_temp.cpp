#include <iostream>

using namespace std;

bool prime(int x)
{
    for(int i=2;i<=x/2;i++)
    {
        if(x/i==0)
            return false;
    }
    return true;
}
int main()
{
    char a[10000][3];
    int n,m,i,j,k;
    int l;
    cin>>n>>m;
    if(prime(n)==false)
    {
        for(i=1,j=2;j<=m;j++)
        {
            if(prime(j)==true)
            {
                for(k=j;k>=j,k<=m;k++)
                {
                    if(prime(k)==true&&k<(n+j)&&k>(n-j)&&k>(j-n))
                    {a[i][3]=k;a[i][2]=j;a[i][1]=n;i++;}
                }
            }
        }
    }
    else
    {
        for(i=1,j=1;j<=m;j++)
        {
            for(k=j;k>=j,k<=m;k++)
            {
                if(prime(k)==true&&k<(n+j)&&k>(n-j)&&k>(j-n))
                {a[i][3]=k;a[i][2]=j;a[i][1]=n;i++;}
            }
        }
    }
    cout<<i<<endl;
    for(l=1;l<=i;l++)
    {
        cout<<a[l][1]<<" "<<a[l][2]<<" "<<a[l][3]<<endl;
    }
    return 0;
}

