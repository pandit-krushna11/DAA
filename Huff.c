#include<stdio.h>
#define HT 100
// typedef struct heap *h;
typedef struct node
{
    char c;
    int f;
    struct node *l,*r;
}node;

typedef struct heap
{
    int size;
    int space;
    struct node** array;
}heap;

node* newnode(char c, int f)
{
    node* temp = (node *)malloc (sizeof(node));
    temp->l=NULL;
    temp->r=NULL;
    temp->c=c;
    temp->f=f;
    return temp;
}
heap* createH(int space)
{
    heap* MH = (heap*)malloc (sizeof(heap));
    MH->size=0;
    MH->space=space;
    MH->array=malloc(MH->space * sizeof(*MH->array));
    return MH;
}
void swap_node(node** a, node** b)
{
    node* t= *a;
    *a=*b;
    *b=t;
}
void Hheapify(heap* heap, int idx) // min heap
{
    int smallest = idx;
    int l = 2*idx + 1;
    int r = 2*idx + 2;
    if(l < heap->size && heap->array[l]->f < heap->array[smallest]->f)
        smallest=l;
    if(r < heap->size && heap->array[r]->f < heap->array[smallest]->f)
        smallest=l;
    if(smallest!=idx)
    {
        swap_node(&heap->array[smallest],&heap->array[idx]);
        Hheapify(heap,smallest);
    }
}
int isSizeOne(heap* h)
{
    return (h->size==1) ;
}
node* extractMin(heap* h)
{
    node* temp = h->array[0];
    h->array[0] = h->array[h->size - 1];
    --(h->size);
    Hheapify(h,0);
    return temp;
}
void insertHeap(heap* h, node* n)
{
    int i=h->size - 1; // restore up
    ++(h->size);
    while(i && n->f < h->array[(i-1)/2]->f)
    {
        h->array[i] = h->array[(i-1)/2];
        i=(i-1)/2;
    }
    h->array[i] = n;
}
void buildHeap(heap* h)
{
    int n = h->size - 1;
    int i;
    for(i=(n-1)/2;i>=0;--i)
        Hheapify(h,i);
}
void printArr(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
int isLeaf(node* root)
{
    return !(root->l) && !(root->r) ;
}
heap* createBuildHeap(char ch[],int fr[],int size)
{
    int i;
    heap* h = createH(size);
    for(i=0;i<size;i++)
        h->array[i] = newnode(ch[i],fr[i]);
    h->size = size;
    buildHeap(h);
    return h;
}

node* buildHuffmanTree(char ch[],int fr[],int size)
{
    node *l,*r,*top;
    heap *h = createBuildHeap(ch,fr,size);
    while(!isSizeOne(h))
    {
        l = extractMin((h));
        r = extractMin((h));
        top = newnode('$', l->f+r->f);
        top->l = l;
        top->r = r;
        insertHeap(h,top);
    }
    return extractMin(h);
}
void printCodes(node* root, int arr[], int top)
{
    if (root->l)
    {
        arr[top] = 0;
        printCodes(root->l, arr, top + 1);
    }
    if (root->r)
    {
        arr[top] = 1;
        printCodes(root->r, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("%c: ", root->c);
        printArr(arr, top);
    }
}
void HuffmanCodes(char character[], int frequency[], int size)
{
	node* root = buildHuffmanTree(character, frequency, size);
	int arr[HT], top = 0;
	printCodes(root, arr, top);
}


void main()
{
	char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int frequency[10] = {5, 9, 12, 13, 16, 45};
	int size;
    size = 2;
	//size = sizeof(arr)/sizeof(arr[0]);
	HuffmanCodes(arr, frequency, size);
}
