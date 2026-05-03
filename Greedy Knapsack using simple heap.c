#include<stdio.h>
    doKnap(int cap, float *w,float *v, int n)
    {
        int k;
        float val,r[10];
        int i,b[10];
        //n = *s;
        for(i=0;i<n;i++)
            r[i]=v[i]/w[i];
        for(i=0;i<n;i++)
            printf("r[%d] = %f\n",i,r[i]);
        for(i=0;i<n;i++)
            b[i]=i;

        makeheap(r,b,n);
        //k = *s;
        k=n;
        val = 0;
        //apply knap inclusion using delete max from max-heap
        //for(i=0;k>0;i++)
        i=0;
        while(k>=0)
        {
            if(cap>0 && w[b[0]]<=cap)
            {
                //makeheap(r,b,n);
                //cap = cap - w[b[0]];
                //val = val + v[b[0]];
                printf("current-%d value %f\n",i,val);
                printf("current-%d value %f\n",i,cap);
                i++;
                b[0] = b[k];
                k--;
                restoredown(0,r,b,k);
            }
            else
                break;
        }
        if(cap>0)
        {
            val = val + v[b[i]]*(cap/w[b[i]]);
        }
    printf("total value %f\n",val);
    printf("total value %f\n",cap);
    }

    void restoredown(int p,float *r,int *b,int n)
    {
        int i,k;
        float v;
        v=r[p];
        k=b[p];
        printf("v = %f\n",v);
        printf("index = %d\n",k);
        //while(p <= ((n+1)/2)-1)
        while(p <= ((n+1)/2)-1)
        {
            i=2*p+1;
            if(i<n && r[b[i]] < r[b[i+1]])
                i++;
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
    void makeheap(float *r,int *b,int n)
    {
        int i;
        for(i=((n+1)/2)-1;i>=0;i--)
        {
            printf("Itr %d\n",i);
            restoredown(i,r,b,n);
        }
        printf("\n  my Heap \n");
        for(i=0;i<=n;i++)
            printf("%f \t",r[i]);
        printf("\n \n");
        for(i=0;i<=n;i++)
            printf("%d \t",b[i]);
    }

void main()
{
    float w[10]={1,4,5,3,3};
    float v[10]={2,28,25,18,9};
    int n,i;
    n=5;
    /*printf("enter # objects\n");
    scanf("%d",&n);
    printf("enter your store value table\n");
    for(i=0;i<n;i++)
        {
            printf("element %d value\n",i);
            scanf("%f",&v[i]);
            printf("element %d weight\n",i);
            scanf("%f",&w[i]);
        }*/
    for(i=0;i<n;i++)
        {
            printf("element %d:- weight = %f\t value = %f\n",i,w[i],v[i]);
            //printf("address %u : %u\n\n ",&a[0][i],&a[1][i]);
        }
    doKnap(12, w,v,(n-1));
}






////Tech 1
/*maxheapify(float *array, int idx)
{
    int largest = idx;
    int left = (idx << 1) + 1;  // left = 2*idx + 1
    int right = (idx + 1) << 1; // right = 2*idx + 2
    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;
    if (largest != idx)
    {
        swap(array[largest], array[idx]);
        maxheapify(array, largest);
    }
}
void heapSort(int* array, int size)
{
    while (size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --size;
        maxHeapify(maxHeap, 0);
    }
}*/
    /*void restoredown(int p,int *a,int n)
    {
        int i,v;
        v=a[p];
        printf("v = %d\n",v);
        while(p <= ((n+1)/2)-1)
        {
            i=2*p+1;
            if(i<n && a[i]<a[i+1])
            {
                i++;
                printf("i = %d\n",i);
            }
            if(v>=a[i])
            {
                printf("a[%d] = %d\n",i,a[i]);
                break;
            }
            printf("swap a[%d] = %d with a[%d] = %d\n",p,a[p],i,a[i]);
            a[p]=a[i];
            p=i;
        }
        a[p]=v;
    }*/
