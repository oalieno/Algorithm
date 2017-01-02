// Complexity : O(logN)
// one-based

void MaxHeapify(int A[],int now,int L){
    while(now <= L/2){
        int left = now*2,right = now*2+1,largest = now;
        if(left <= L && A[left] > A[largest]) largest = left;
        if(right <= L && A[right] > A[largest]) largest = right;
        if(largest != now){
            swap(A[largest],A[now]);
            now = largest;
        }
        else break;
    }
}

void HeapSort(int A[],int L){
    for(int i=L/2;i;i--)MaxHeapify(A,i,L);
    for(int i=L;i;i--){
        swap(A[1],A[i]);
        MaxHeapify(A,1,i-1);
    }
}
