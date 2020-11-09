#include <bits/stdc++.h>

using namespace std;

struct a
{
    int x=0;
    int y;
};
bool sx(a a1,a a2)
{
    return a1.x>a2.x;
}
bool sy(a a1,a a2)
{
    return a1.y<a2.y;
}
int main()
{
    int n,m;
    cin>>n>>m;
    a aa[n+1];
    int e,s;
    int b[n+1],c[n+1];
    for(int i=0; i<n; i++)
    {
        aa[i].y=i;
    }
    for(int i=0; i<m; i++)
    {
        cin>>s>>e;
        for(int j=s; j<=e; j++)
        {
            aa[j-1].x++;

        }
    }
    sort(aa,aa+n,sx);

    for(int i=0; i<n; i++)
    {
        b[i]=aa[i].y;
    }
    sort(aa,aa+n,sy);
    c[0]=1;
    c[1]=n;
    int co=1;
    for(int i=2; i<n; i+=2)
    {
        c[i]=n-co;
        co++;
    }
    co=2;
    for(int i=3; i<n; i+=2)
    {
        c[i]=co;
        co++;
    }
    for(int i=0; i<n; i++)
    {
        aa[b[i]].y=c[i];
    }
    for(int i=0; i<n; i++)
    {
        cout<<aa[i].y<<" ";
    }
}
