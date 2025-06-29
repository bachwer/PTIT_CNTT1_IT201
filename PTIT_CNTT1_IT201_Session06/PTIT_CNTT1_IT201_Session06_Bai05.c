#include <stdio.h>


int timMax(int a[], int n) {
    if (n == 1)
        return a[0];
    int max = timMax(a, n - 1);
    return (a[n - 1] > max) ? a[n - 1] : max;
}


int timMin(int a[], int n) {
    if (n == 1)
        return a[0];
    int min = timMin(a, n - 1);
    return (a[n - 1] < min) ? a[n - 1] : min;
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
        return 0;
    }

    int a[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int min = timMin(a, n);
    int max = timMax(a, n);

    printf("%d, %d\n", min, max);

    return 0;
}