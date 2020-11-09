#include <bits/stdc++.h>

using namespace std;

queue <int> D;
queue <int> Q;
int arr[10000][10000];
int n,m,s,mx=INT_MIN,e,t,rr,gg;
void walk(int i,int j,int r,int g,int sum,int d)
{
    if(arr[i][j]=='R') {r++; d=d*10;}
    else if(arr[i][j]=='G') {g++; d=(d*10)+1;}
    if(j<m-1) { sum=sum*10; walk(i,j+1,r,g,sum,d);}
    if(i<n-1) { sum=(sum*10)+1; walk(i+1,j,r,g,sum,d);}


    if(i==n-1&&j==m-1)
    {
        if(r>=g) s=2*g;
        else s=2*r;
        if(s>mx) {mx=s;e=sum;t=d;rr=r;gg=g;}
    }


}
int main()
{
stack <int> st;
stack <int> cl;
   cin>>n>>m;
    char x[m+1];
   for(int i=0;i<n;i++)
   {
       cin>>x;
      for(int j=0;j<m;j++)
      {
          arr[i][j]=x[j];
      }
   }
   walk(0,0,0,0,1,1);

   cout<<mx<<"\n";

   while(e>1)
   {
       st.push(e%10);
       e=e/10;
   }
   while(t>1)
   {
       cl.push(t%10);
       t=t/10;
   }
   int p;
   //cout<<rr<<" "<<gg;
   if(rr>gg) p=rr;
   else p=gg;
   int rrr=0,ggg=0;
   while(!st.empty()&&!cl.empty())
   {   // cout<<p<<" ";
      if(rr>gg)
      {
          if(cl.top()==0)
          {
              if(p>mx/2) cout<<"N";
            else {cout<<"Y";rrr++;}
              p--;
          }
            else if(cl.top()==1) {cout<<"Y";ggg++;}
      }
      else if(gg>rr)
      {
           if(cl.top()==1)
            {
              if(p>mx/2) cout<<"N";
              else {cout<<"Y";ggg++;}
              p--;
            }
            else if(cl.top()==0) {cout<<"Y";rrr++;}
      }
      else cout<<"Y";

      cout<<" ";
       if(st.top()==1) cout<<"D";
       else cout<<"R";
       cout<<"\n";
       st.pop();
       cl.pop();
   }
   if(mx!=0)
{if(rrr==0&&ggg==0) cout<<"Y";
else if(rrr==ggg) cout<<"N";
else if(rrr!=ggg) cout<<"Y";}
else cout<<"N";


    return 0;
}
