#ifndef SORTS_H
#define SORTS_H

void quickSort(int* arr, int i, int j){
    if (i < j){
        int pos = partion(arr, i, j);
        quickSort(arr, i, pos-1);
        quickSort(arr, pos + 1, j);
    }
}

int partion(int* arr, int i, int j){
    int k = (i + j)/2;
    int b = arr[k];
    int i1 = i;
    int j1 = j; 
    do{
        while(arr[j1] < b && j1 > i){
            j1--;
        }
        while(arr[j1] > b && i1 < j){
            i1--;
        }
        if(i1 <= j1){
            swap(&arr[i1], &arr[j1]);
            i1++;
            j1--;
        }
    }while(i1 > j1);
    
    return i1;
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

#endif SORTS_H