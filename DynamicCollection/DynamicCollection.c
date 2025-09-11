#include <stdio.h>
#define infinity 9223372036854775807
long long arreglo[10000000];

void MergeSort(long long arreglo[], int left, int right);
void Merge(long long arreglo[], int left, int right, int mid);
long long BinarySearchFirstOccurrence(long long arreglo[], int left, int right, long long k);
long long BinarySearchLastOccurrence(long long arreglo[], int left, int right, long long k);
long long BinarySearch(long long arreglo[], int left, int right, long long k);

int main() {
    int n, q, op;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%lld",&arreglo[i]);
    MergeSort(arreglo, 0, n - 1);
    long long  k, a, b;
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%lld",&k);
            int r = BinarySearch(arreglo, 0, n - 1, k);
            if ((r * -1) - 1 == n) {
                arreglo[n] = k;
                n++;
            } else if (r < 0) {
                arreglo[(r * -1) - 1] = k;
            }
        } else {
            scanf("%lld %lld", &a, &b);
            int r1 = BinarySearchFirstOccurrence(arreglo, 0, n - 1, a);
            int r2 = BinarySearchLastOccurrence(arreglo, 0, n - 1, b);
            if (r1 < 0) {
                r1 = (r1 * -1) - 1;
            }
            if (r2 < 0) {
                r2 = (r2 * -1) - 2;
            }
            printf("%d\n", r2 - r1 + 1);
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
    for (int i = 0; i < n2; i++) 
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

long long BinarySearchFirstOccurrence(long long arreglo[], int left, int right, long long k) {
    int r1, r2;
    r1 = BinarySearch(arreglo, left, right, k);
    if (r1 < 0) {
        return r1;
    } else {
        while (r1 >= 0) {
            r2 = r1;
            r1 = BinarySearch(arreglo, left, r1 - 1, k);
        }
        return r2;
    }
}

long long BinarySearchLastOccurrence(long long arreglo[], int left, int right, long long k) {
    int r1, r2;
    r1 = BinarySearch(arreglo, left, right, k);
    if (r1 < 0) {
        return r1;
    } else {
        while (r1 >= 0) {
            r2 = r1;
            r1 = BinarySearch(arreglo, r1 + 1, right, k);
        }
        return r2;
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