void MaxHeapify(int A[],int start,int end){
    int parent = start,son = parent*2+1;
    while(son <= parent){
        if(son+1 <= end && A[son] < A[son+1])son++;
        if(A[parent] > A[son])return;
        else{
            swap(A[parent],A[son]);
            parent = son;
            son = parent*2+1;
        }
    }
}

void HeapSort(int A[],int L){
    for(int i=len/2-1;i>=0;i--)MaxHeapify(A,i,len-1);
    for(int i=len-1;i>0;i--){
        swap(A[0],A[i]);
        MaxHeapify(A,0,i-1);
    }
}
