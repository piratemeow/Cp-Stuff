#include <bits/stdc++.h>
using namespace std;


string sum (string a, string b)
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

string mul(string a, string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    
    int n,m;
    
    bool flag ;
    if (a.size()<b.size())
    {
        flag = 1;
        n=a.size();
        m=b.size();
    }
    else
    {
        flag = 0;
        n=b.size();
        m=a.size();
    }
    
    
    int f = 0;
    
    int i = 0;
    string ans;
    if (flag)
    { for (i=0;i<n;i++)
        {
            string x;
            for (int j=0;j<m;j++)
            {
                int k = (a[i]-'0')*(b[j]-'0')+f;
                x+=((k%10)+'0');
                f=k/10;
            }
            if (f)
            x+=(f+'0');
            cout<<x<<endl;
            reverse(x.begin(),x.end());
            
            int g=i;
            while (g--)
            {
                x+='0';
            }
            ans = sum(ans,x);
            
            cout<<ans<<"ans"<<endl;
            //reverse(ans.begin(),ans.end());
        }
    }
    
    else
    {
         for (i=0;i<n;i++)
        {
            string x;
            for (int j=0;j<m;j++)
            {
                int k = (b[i]-'0')*(a[j]-'0')+f;
                x+=((k%10)+'0');
                f=k/10;
            }
            if (f)
            x+=(f+'0');
            cout<<x<<endl;
            reverse(x.begin(),x.end());
            
            int g=i;
            while (g--)
            {
                x+='0';
            }
            ans = sum(ans,x);
            
            cout<<ans<<"ans"<<endl;
            //reverse(ans.begin(),ans.end());
        }
        
        
        
    }
    
    //reverse(ans.begin(),ans.end());
    return ans ;
    
}
int main ()
{
    string a,b;
    cin>>a>>b;
    cout<<mul(a,b)<<endl;    
    
}
