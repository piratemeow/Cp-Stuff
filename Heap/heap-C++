#include <bits/stdc++.h>

using namespace std;

class heap{


    int i=1;
    int* arr;
    int sz;

public:
    heap(int sz)
    {
        arr = new int[sz+1];
        this->sz=sz+1;
    }

    void insert(int ele)
    {
        if (i==sz+1)
        {
            cout<<"The heap is full\n";
        }

        arr[i]=ele;
        cout<<arr[i]<<endl;
        int p = i;
        while (p>1)
        {
            int pr = p/2;
            if (arr[pr]>arr[p])
            {
                swap(arr[pr],arr[p]);
                p=pr;
            }
            else
                break;
        }
        //cout<<arr[i]<<endl;
        i++;
    }


    void dele()
    {
        if (i==1)
        {
            cout<<"Nothing to delete\n";
        }

        else
        {
            int k = --i;
           // cout<<arr[0]<<endl;
            arr[1]=arr[k];
            //i--;

            int p = 1;
            while (2*p<=i)
            {
                int j = 2*p;
                if (2*p +1 <=i)
                {
                    if (arr[j]>arr[j+1])
                    {
                        j++;
                    }
                }

                if (arr[j]<arr[p])
                {
                       swap(arr[j],arr[p]);
                       
                }
                

                else 
                    break;
            }
        }
    }

    void display()
    {
        for (int j=1;j<i;j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
};
int main ()
{
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    heap* h = new heap(n);
    while (n--)
    {
        int x;
        cin>>x;
        h->insert(x);
    }

    h->display();

    h->dele();
    h->display();
    h->dele();

    h->display();
}
