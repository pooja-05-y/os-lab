#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("enter no of elements");
    scanf("%d", &n);

  int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int largest =0, second =0;

    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if (a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }
    printf("Second largest = %d\n", second);

    return 0;
}
