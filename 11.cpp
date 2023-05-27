#include<iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n){
    int leftNode = 2 * i + 1;
    int rightNode = 2 * i + 2;
    int maxNode = i,temp;
    if ((leftNode < n) && (a[leftNode] > a[maxNode]))
    {
        maxNode = leftNode;
    }
    if ((rightNode < n) && (a[rightNode] > a[maxNode]))
    {
        maxNode = rightNode;
    }
    if(maxNode != i){
        temp = a[i];
        a[i] = a[maxNode];
        a[maxNode] = temp;
        MaxHeapify(a,maxNode,n);
    }
}

void buildMaxHeap(int a[], int n){
    for (int i = n/2; i >= 0; i--)
    {
        MaxHeapify(a,i,n);
    }
}

void heapSort(int a[], int n){
    buildMaxHeap(a,n);
    int temp;
    for (int i = n-1; i >= 0; i--)
    {
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        MaxHeapify(a,0,i);
    }
    
}

int main(int argc, char const *argv[])
{
    
    return 0;
}