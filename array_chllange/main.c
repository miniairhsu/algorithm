#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length; //no of elements in array
};

void Display(struct Array arr)
{
    int i;
    printf("\nElement are\n");
    for(i=0;i<arr.length;i++)
        printf("%d\r\n", arr.A[i]);
}

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size) 
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(index >= 0 && index <= arr->length) {
        for(i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if(index >= 0 && index <= arr->length) {
        x = arr->A[index];
        for(i = index; i < arr->length-1; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp =*x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for(i = 0; i < arr->length; i++) {
        if(key == arr->A[i])
            return i;
    }
    return -1;
}

int LinearSearch_improve(struct Array *arr, int key)
{
    int i;
    for(i = 0; i < arr->length; i++) {
        if(key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid]) 
            h = mid - 1;
        else 
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(int a[], int l, int h, int key)
{
    int mid;
    if(l <= h) {
        mid = (l+h)/ 2 ;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return RBinarySearch(a, l, mid -1, key);
        else 
            return RBinarySearch(a, mid+1, h, key);
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if(index>=0 && index < arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for(i = 1; i < arr.length; i++) {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int max1(int a[], int n)
{
    int i;
    int max = a[0];
    for(i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for(i = 1; i < arr.length; i++) {
        if(arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int min1(int a[], int n)
{
    int i;
    int min = a[0];
    for(i = 0; i < n; i++) {
        if(a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int s = 0;
    int i;
    for(i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for(i = arr->length-1, j = 0; i>=0; i--, j++) {
        B[j] = arr->A[i];
    }

    for(i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
}

void Reverse_Swap(struct Array *arr)
{
    int i, j;
    for(i = 0, j = arr->length-1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if(arr->length == arr->size) {// no free space
        return;
    }
    while(i >= 0 && arr->A[i] > x) {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for(i = 0; i < arr.length-1; i++) {
        if(arr.A[i] > arr.A[i+1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr) 
{
    int i, j;
    i = 0;
    j = arr->length - 1;
    while(i < j) {
        while(arr->A[i] < 0) i++;
        while(arr->A[j] > 0) j--;
        if(i < j) swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length && j < arr2->length) {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else 
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

//pick up the same item for only once
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length && j < arr2->length) {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

//only pick up the common item 
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length && j < arr2->length) {
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length && j < arr2->length) {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    //missing sigle element
    int a[] = {6,7, 8 , 9 , 10, 11, 13, 14, 15, 16, 17};
    int size = 11;
    int l = a[0];
    int h = a[size-1];
    int diff = l - 0;
    for(int i = 0; i < size; i++) {
        if(a[i] - i != diff) {
            printf("missing element is %d\r\n", i+diff);
            break;
        }
    }

    //missing multiple elements
    int a1[] = {6,7, 8 , 9, 11, 12, 15, 16, 17, 18, 19};
    int size1 = 11;
    int l1 = a1[0];
    int h1 = a1[size1-1];
    int diff1 = l1 - 0;
    for(int i = 0; i < size1 - 1; i++) {
        if(a1[i] - i != diff1) {
            while(diff1 < a1[i] - i) {
                printf("%d\n", i + diff1);
                diff1++;
            }
        }
    }

    //find missing element of unsorted array
    int a2[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int a3[12] = {0};
    int l2 = 1; //min value in array
    int h2 = 12; //max value in array
    for(int i = 0; i < 10; i++) {
        int j = a2[i];
        a3[j]++;
    }
    for(int i = l2; i < h2; i++) {
        if(a3[i] == 0)
            printf("missing element %d\r\n", i);
    }

    //check duplicate in array
    int a4[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int lastDuplicate = 0;
    for(int i = 0; i < 9; i++) {
        if(a4[i] == a4[i+1] && a4[i] != lastDuplicate) {
            printf("%d\r\n", a4[i]);
            lastDuplicate = a4[i];
        }
    }

    //count duplicates in array
    for(int i = 0; i < 9; i++) {
        if(a4[i] == a4[i+1]) {
            int j = i + 1;
            while(a4[j] == a4[i]) j++;
            printf("%d duplicate %d times\r\n", a4[i], j-i);
            i = j - 1;
        }
    }

    //find and count duplicate elements
    int a5[21] = {0};
    for(int i = 0; i < 10; i++) {
        a5[a4[i]]++;
    }
    for(int i = 0; i <= 20; i++) {
        if(a5[i] > 1) printf("duplicate element %d times %d\r\n", i, a5[i]);
    }

    //find unsorted duplicate array 
    int a6[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    for(int i = 0; i < 9; i++) {
        int count = 1;
        if(a6[i] != -1) {
            for(int j  = i + 1; j < 10; j++) {
                if(a6[i] == a6[j]) {
                    count++;
                    a6[j] = -1;
                }
            }
        }
        if(count > 1) printf("%d repeat %d times \r\n", a6[i], count);
    }

    //find unsorted duplicate array by simple hash table
    int a7[9] = {0};
    int a8[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    for(int i = 0; i < 10; i++) {
        a7[a8[i]]++;
    }
    for(int i = 0; i <= 8; i++) {
        if(a7[i] > 1) {
            printf("%d hash repeat %d times \r\n", i, a7[i]);
        }
    }

    //find pair element with sum k
    int a9[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    for(int i = 0; i < 9; i++) {
        for(int j = i+1; j < 10; j++) {
            if(a9[i] + a9[j] == 10) {
                printf("sum of %d %d is 10\r\n", a9[i], a9[j]);
            }
        }
    }

    //find pair element with sum k with hash table
    int a10[17] = {0};
    for(int i = 0; i < 10; i++) {
        if(a10[10-a9[i]] != 0) printf("hash sum of %d %d is 10\r\n", a9[i], 10 - a9[i]);
        a10[a9[i]]++;
    }

    //find pair element with sum k sorted array 
    int a11[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int i1 = 0;
    int j1 = 9;
    while(i1 < j1) {
        if(a11[i1] + a11[j1] == 10) {
            printf("sum of %d %d is 10\r\n", a11[i1], a11[j1]);
            i1++;
            j1--;
        } else if(a11[i1] + a11[j1] < 10) {
            i1++;
        } else 
            j1--;
    }

    //find max min in single scan 
    int a12[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    int min = a12[0];
    int max = a12[0];
    for(int i = 0; i < 10; i++) {
        if(a12[i] < min) {
            min = a12[i];
        } else if(a12[i] > max) {
            max = a12[i];
        }
    }
    printf("max is %d min is %d\r\n", max, min);
    return 0;
}