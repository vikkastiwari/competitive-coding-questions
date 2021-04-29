#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], i;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends

void rotate(int arr[], int n)
{
    int rotArr[n], k = 1;
    for (int i = 0; i < n; i++)
    {
        rotArr[i] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[(i + k) % n] = rotArr[i];
    }
}