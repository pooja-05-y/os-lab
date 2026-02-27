#include <stdio.h>
#include <limits.h>

int main(){
    int n;
    printf("enter no of elements");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int smallest =INT_MAX, second =INT_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i] < smallest) {
            second = smallest;
            smallest = a[i];
        } else if (a[i] < second && a[i] != smallest) {
            second = a[i];
        }
    }
    printf("Second smallest = %d\n", second);
    return 0;
}
