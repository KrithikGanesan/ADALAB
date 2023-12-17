#include <iostream>
using namespace std;

int main()
{
    int n,i,j,a[10][10],s[10],d[10],v,k,min,u;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    cout<<"Enter the cost matrix \n";
    cout<<"Enter 999 if no edge between vertices \n";
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    cout<<"Enter the source vertex \n";
        cin>>v;
    for(i=1;i<=n;i++)
    {
        s[i]=0;
        d[i]=a[v][i];
    }
    d[v]=0;
    s[v]=1;
    for(k=2;k<=n;k++)
    {
        min=999;
        for(i=1;i<=n;i++)
            if(s[i]==0 && d[i]<min)
            {
                min=d[i];
                u=i;
            }
        s[u]=1;
        for(i=1;i<=n;i++)
            if(s[i]==0)
            {
                if(d[i]>(d[u]+a[u][i]))
                d[i]=d[u]+a[u][i];
            }
    }
    cout<<"The shortest distance from "<<v<<" is: \n";
    for(i=1;i<=n;i++)
        cout<<v<<" -> "<<i<<" = "<<d[i];
        cout<<endl;
    return 0;
}
