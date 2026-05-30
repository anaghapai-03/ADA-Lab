#include<stdio.h>
void main()
{

    float p[100],w[100],x[100],n,maxcap,total=0.0,temp1,temp2;
    printf("enter the  number of elements\n");
    scanf("%f",&n);
    float rc=0;
    printf("Enter the values\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&p[i]);
        scanf("%f",&w[i]);
        x[i]=0.0;

    }
    printf("enter the maximum capacity\n");
    scanf("%f",&maxcap);
    rc=maxcap;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n-1;k++)
        {
            if(p[i]/w[i]>p[k]/w[k])
            {
                temp1=p[i];
                p[i]=p[k];
                p[k]=temp1;
                temp2=w[i];
                w[i]=w[k];
                w[k]=temp2;

            }
        }
    }
    int j;
    for( j=0;j<n;j++)
    {

        if(w[j]<rc)
        {
            rc-=w[j];
            x[j]=1.0;
        }
        else
            break;

    }
    if(j<n)
    {

        x[j]=rc/w[j];

    }
    for(int i=0;i<n;i++)
    {
        total=total+(x[i]*p[i]);
    }
    printf("the total profit: %f",total);
}
