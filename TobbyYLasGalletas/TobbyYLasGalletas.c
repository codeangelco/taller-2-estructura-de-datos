#include <stdio.h>
#define infinity 2147483647
long long arreglo[1000000];

void Merge(long long arreglo[], int left, int right, int mid);
void MergeSort(long long arreglo[], int left, int right);
long long BinarySearchLastOccurrence(long long arreglo[], int left, int right, long long k);
long long BinarySearch(long long arreglo[], int left, int right, long long k);

int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%lld",&arreglo[i]);
        MergeSort(arreglo, 0, n-1);
        long long t, q;
        scanf("%lld",&t);
        while (t--) {
            scanf("%lld",&q);
            printf("%lld",BinarySearchLastOccurrence(arreglo, 0, n-1, q));
            if (t >= 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}

void MergeSort(long long arreglo[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arreglo, left, mid);
        MergeSort(arreglo, mid + 1, right);
        Merge(arreglo, left, right, mid);
    }
}

void Merge(long long arreglo[], int left, int right, int mid) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++) 
        L[i] = arreglo[i + left];
    for (int i = 0; i < n1; i++) 
        R[i] = arreglo[i + mid + 1];
    L[n1] = infinity;
    R[n2] = infinity;
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (L[i] <  R[j])
            arreglo[k] = L[i++];
        else
            arreglo[k] = R[j++];
    }
}

long long BinarySearchLastOccurrence(long long arreglo[], int left, int right, long long k) {
    int r1, r2;
    r1 = BinarySearch(arreglo, left, right, k);
    if (r1 < 0) {
        return (r1 * -1) - 1;
    } else {
        while (r1 >= 0) {
            r2 = r1;
            r1 = BinarySearch(arreglo, r1 + 1, right, k);
        }
        return r2 + 1;
    }
}

long long BinarySearch(long long arreglo[], int left, int right, long long k) {
    int m;
    while (left <= right) {
        m = (left + right) / 2;
        if (arreglo[m] == k) {
            return m;
        } else {
            if (arreglo[m] > k) {
                right = m - 1;
            } else {
                left = m + 1;
            }
        }
    }
    return (left * -1) - 1;
}