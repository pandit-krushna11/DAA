#include<stdio.h>
    doKnap(float cap, float *w,float *v, int n)
    {
        int k,m;
        float val,r[10];
        int i,b[10];
        //n = *s;
        for(i=0;i<n;i++)
            r[i]=v[i]/w[i];
        for(i=0;i<n;i++)
        {
            printf("r[%d] = %f  ",i,r[i]);
        }
        for(i=0;i<n;i++)
        {
            b[i]=i;
            //printf("b[%d] = %b  |  ",i,b[i]);
        }
        makeheap(r,b,n);
        //k = *s;
        k=n;
        val = 0;
        /*i = del(r,b,&k);
        printf("%d deleted max %d\n\n",i,k);
        for(i=0;i<k;i++)
            printf("%d   ",b[i]);

        i = del(r,b,&k);
        printf("%d deleted max %d\n\n",i,k);
        for(i=0;i<k;i++)
            printf("%d   ",b[i]);*/


        //apply knap inclusion using delete max from max-heap
        //for(i=0;k>0;i++)
        while(k>=1)
        {
        if(cap>0 && cap>=w[b[0]])
        {
        i = del(r,b,&k);
        printf("%d deleted max \n\n",i);

        printf("\n \n");
        for(i=0;i<k;i++)
            printf("%d \t",b[i]);
        printf("\n\n");

        cap = cap - w[i];
        val = val + v[i];
        printf("current-%d value %f\n",k,val);
        printf("current-%d capac %f\n",k,cap);
        }
        else
            break;
        }
        if(cap>0)
            val = val + v[b[i]]*(cap/w[b[i]]);
        printf("total-%d value %f\n",k,val);
        printf("total-%d capac %f\n",k,cap);
        /*for(i=0;i<n;i++)
            printf("b[%d] = %d  ",i,b[i]);
        printf("\n\n");
        for(i=0;i<n;i++)
            printf("r[%d] = %f  ",b[i],r[b[i]]);*/
    }

    void restoredown(int p,float *r,int *b,int n)
    {
        int i,k;
        float v;
        v=r[b[p]];
        k=b[p];
        printf("v = %f\n",v);
        //printf("index = %d\n",k);
        while(p < n/2)
        {
            i=2*p+1;
            //i++;
            printf("%d left %f  right %f\n",i,r[b[i]],r[b[i]+1]);
            if((i)<n && r[b[i]]<r[b[i+1]])
            {
                i++;
                printf("thayu \n");
            }
            if(v>=r[b[i]])
                break;
            printf("swap ind %d with %d\n",p,i);
            printf("swap val %f with %f\n",r[b[p]],r[b[i]]);
            printf("swap idx %d with %d\n",b[p],b[i]);
            b[p]=b[i];
            p=i;
        }
        b[p]=k;
    }

    int del(float *r,int *b,int *k)
    {
        int v,l,i;
        //v=r[*b];
        l=*b;
        printf("1st %d last %d\n",b[0],b[*k - 1]);
        b[0]=b[*k-1];
        (*k)--;
        printf("inside loop n = %d\n",*k);
        restoredown(0,r,b,*k);
        return l;
    }
    void makeheap(float *r,int *b,int n)
    {
        int i;
        for(i=((n/2)-1);i>=0;i--)
            restoredown(i,r,b,n);
        printf("\n  my Heap \n");
        for(i=0;i<n;i++)
            printf("%f \t",r[b[i]]);
        printf("\n \n");
        for(i=0;i<n;i++)
            printf("%d \t",b[i]);
        printf("\n\n");
    }

void main()
{
    float w[10]={1,4,5,3,3};
    float v[10]={2,28,25,18,9};
    int n,i;
    float x;
    n=5;
//    printf("enter # objects\n");
//    scanf("%d",&n);
//    printf("enter your store value table\n");
//    for(i=0;i<n;i++)
//        {
//            printf("element %d value\n",i);
//            scanf("%f",&v[i]);
//            printf("element %d weight\n",i);
//            scanf("%f",&w[i]);
//        }
    for(i=0;i<n;i++)
        {
            printf("element %d:- weight = %f\t value = %f\n",i,w[i],v[i]);
            //printf("address %u : %u\n\n ",&a[0][i],&a[1][i]);
        }
    x=10;
    doKnap(x,w,v,n);
}
