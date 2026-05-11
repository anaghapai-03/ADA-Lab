#include<stdio.h>

void heapify(int a[], int n, int p)
{
    int c, item;

    item = a[p];
    c = 2 * p + 1;

    while(c < n)
    {
        // Find larger child
        if(c + 1 < n)
        {
            if(a[c] < a[c + 1])
            {
                c++;
            }
        }

        // Move larger child up
        if(item < a[c])
        {
            a[p] = a[c];
            p = c;
            c = 2 * p + 1;
        }
        else
        {
            break;
        }
    }

    a[p] = item;
}

void build_heap(int a[], int n)
{
    int i;

    for(i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}

void heap_sort(int a[], int n)
{
    int i, temp;

    build_heap(a, n);

    for(i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    int a[100], n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter the array:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    heap_sort(a, n);

    printf("Sorted array:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
