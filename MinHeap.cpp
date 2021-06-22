#include <iostream>

using namespace std;

void swap(int* x, int* y) { //swap using pointers
    int temp = *x;
    *x = *y;
    *y = temp;
}
class MinHeap {
    int* heap; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(int a[], int size); // Constructor

    void heapify(int i); // To heapify subtree rooted with index i

    int parent(int i) { //return index of parent of i
        return (i - 1) / 2;
    }

    int leftchild(int i) { //return index of left child of i
        return (2 * i + 1);
    }
    int rightchild(int i) { //return right child of i
        return (2 * i + 2);
    }

    int delete_minimum(); // extracts root (minimum) element
    int getMin() {
        return heap[0];
    } // Returns minimum

    void insert_ele(int element);
    int delete_indexed_element(int index);
    int delete_element(int element);
    void print_heap();
};

MinHeap::MinHeap(int a[], int size) { //convert the array into heap
    heap_size = size;
    heap = a; // store address of array
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
        heapify(i);
        i--;
    }
}

void MinHeap::heapify(int i) {
    int l = leftchild(i);
    int r = rightchild (i);
    int smallest = i;

    if (l < heap_size && heap[l] < heap[smallest])
        smallest = l;
    if (r < heap_size && heap[r] < heap[smallest])
        smallest = r;
    if (smallest != i) { //one of the child is smaller than the parent
        swap(&heap[i], &heap[smallest]);//swap that child with parent
        heapify(smallest);
    }
}

void MinHeap::insert_ele(int element) {
    if (heap_size == capacity) {
        cout<<"Heap is full";
        return;
    }

    heap_size++;
    heap[heap_size-1] = element; //insert at the end

    int curr_index = heap_size - 1;

    while (curr_index != 0 && heap[parent(curr_index)] > heap[curr_index]) {
       swap(&heap[curr_index], &heap[parent(curr_index)]);
       curr_index = parent(curr_index);
    }//insert and restore the rules of heap

}

int MinHeap::delete_minimum() {
    int root = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size--;

    heapify(0);
}

int MinHeap::delete_indexed_element(int index) {
    //make element at the index the least
    //re store the heap
    //delete the min there by actual indexed element is deleted

    int root = heap[index];
    heap[index] =getMin() - 1;

    int curr_index = index;

    while (curr_index != 0 && heap[parent(curr_index)] > heap[curr_index]) {
       swap(&heap[curr_index], &heap[parent(curr_index)]);
       curr_index = parent(curr_index);
    }

    int deleted = delete_minimum();

    return root;
}

int MinHeap::delete_element(int element) {
    int i, root;
    for (i = 0; i<heap_size; i++)
        if (heap[i] == element) {
            root = delete_indexed_element(i);
        }
    return root;
}

void MinHeap::print_heap() {
    int i;
    for (i = 0; i<heap_size; i++)
        cout<<heap[i]<<"\t";
    cout<<"\n";
}

int main() {
    int arr[] = {1,4,3,7,2,8};

    MinHeap mh(arr,sizeof(arr)/sizeof(arr[0]));
    mh.print_heap();
    mh.delete_element(2);
    mh.print_heap();
    mh.insert_ele(10);
    mh.print_heap();


    return 0;
}

