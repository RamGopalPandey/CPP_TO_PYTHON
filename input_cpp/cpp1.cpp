#include<bits/stdc++.h>
using namespace std;
int main()
{
int x,y,z;
cin>>x>>y>>z;
if(x==y)
{
cout<<"HACKER";
}
else if(x==z)
{
cout<<"CRACKER";
}
else
{
cout<<"CODER";
}
return 0;
}
