#include <bits/stdc++.h>
using namespace std;


string ans (string a , string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    
    string s;
    int f =0;
    int i;
    for( i=0;i<a.size()&&i<b.size();i++)
    {
        int x = a[i]-'0';
        int y = b[i]-'0';
        
        int k = x+y+f;
        
        s+=((k%10)+'0');
        
        f=k/10;
    }
    
    
    while (i<a.size())
    {
        int k = a[i]-'0'+f;
        
        s+=((k%10)+'0');
        f=k/10;
        i++;
    }
    
    while (i<b.size())
    {
        int k = b[i] - '0' +f;
        
        s+=((k%10)+'0');
        f=k/10;
        i++;
    }
    if (f)
    {
        s+=(f+'0');
    }
    reverse(s.begin(),s.end());
    return s;
}
int main ()
{
    string a,b;
    cin>>a>>b;
    cout<<ans(a,b)<<endl;    
    
}
