#include <bits/stdc++.h>

using namespace std;
 long long int x,y,sum=0;
void run( long long int i, long long int j, long long int xx,int yy)
{
    if(i==xx-1&&j==yy-1)
         sum++;
    if(i<xx)
    run(i+1,j,xx,yy);
    if(j<yy)
    run(i,j+1,xx,yy);


}

int main()
{ long long int c=0;
cin>>x>>y;
run(0,0,x,y);
 long long int a=sum*sum;
//cout<<a<<"\n";
for( long long int i=1;i<=x;i++)
{
    for( long long int j=1;j<=y;j++)
    { sum=0;
        if(i==x&&j==y);
        else if(i==1&&j==1);
           //cout<<1<<" "<<1<<" "<<1<<"\n";
        else
        {run(0,0,i,j);
        c+=(sum*sum);
           //cout<<i<<" "<<j<<" "<<sum<<"\n";
        }
    }
}
int u;
if((x+y)%2==0)
    u=a-c;

else u=a-c-1;
while(u>=1000000007)
{
    u-=1000000007;
}

if(x==1||y==1||x==0||y==0 )
    cout<<"0";
else if(x==2||y==2)
    cout<<"2";
else
cout<<u;
    return 0;
}
