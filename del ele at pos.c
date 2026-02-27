#include <stdio.h>

int main() {
    int n;
    printf("enter no of elements");
    scanf("%d", &n);

    int a[1000];  // fixed size for safety
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int pos;
    printf("enter pos");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;

    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
