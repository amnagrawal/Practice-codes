//Codechef- gcdq

//#include<iostream>
//using namespace std;
#include<stdio.h>

int gcd(int a, int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b, a%b);
}

int main()
{
    int tc, n, q, a[100001], l, r, temp;
    //cin>>tc;
    scanf("%d", &tc);
    while(tc--)
    {
        //cin>>n>>q;
        scanf("%d%d", &n, &q);
        for(int i=1; i<=n; i++)
            //cin>>a[i];
            scanf("%d", &a[i]);

        while(q--)
        {
            //cin>>l>>r;
            scanf("%d%d", &l, &r);
            temp = -1;

            for(int j=1; j<=n; j++)
            {
                if((j>=l) && (j<=r))
                {
                    j = r;
                    continue;
                }

                else
                {
                    if(temp == -1)
                        temp = a[j];

                    if((a[j]%temp == 0) && a[j] > temp)
                        continue;

                    temp = gcd(a[j],temp);
                }
            }

            //cout<<temp<<endl;
            printf("%d \n", temp);
        }
    }

    return 0;
}
