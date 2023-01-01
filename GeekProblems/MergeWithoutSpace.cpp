/*n = 4, arr1[] = [1 3 5 7]
m = 5, arr2[] = [0 2 6 8 9]*/
#include <iostream>
#include <algorithm>

using namespace std;
class MergeWithoutSpace{
    public:
        //Function to merge the arrays.
        void builtInMerge(long long arr1[], long long arr2[], int n, int m) {
            // code here
            /*for(int i = 0; i < m; i++){
                //find the first bigger element in arr1 + arr2
                int curr = arr2[i];
                for(int j = 0; j < n + m; j++){
                    int placementIndex;
                    int placementValue;
                    if(j < n){
                        //first arr
                        if(arr1[i] >= curr){ // change to > maybe
                            placementIndex = j;
                            placementValue = arr1[j];
                            arr1[i] = curr;
                            for(int k = j + 1; k < n + m - 1; k++){
                                if(k < n - 1){
                                    arr1[k] = placementValue;
                                    placementValue = arr1[k + 1];
                                }
                                else if(k == n - 1){
                                    arr1[k] = placementValue;
                                    placementValue = arr2[0];
                                }
                                else{
                                    arr2[k - n] = placementValue;
                                    placementValue = arr2[k - n + 1];
                                }
                            }
                        }
                        //second arr
                        else{
                            placementIndex = j;
                            placementValue = arr2[j];
                            arr2[j] = curr;
                            for(int k = j + 1; k < m; k++ ){
                                if(k < m - 1){
                                    arr2[k] = placementValue;
                                    placementValue = arr2[k + 1];
                                }
                                else{
                                    arr2[k - n] = placementValue;
                                }
                            }
                        }
                    }
                }
            }*/

            int i = 0, j = 0, k = n - 1;

            while(i <= k){
                //replace k with arr2j if possible
                if(arr2[j] <= arr1[k]){
                    long long temp = arr2[j];
                    arr2[j] = arr1[k];
                    arr1[k] = temp;
                    j++;
                    k--;

                }
                else{ //if(arr1[i] > arr2[j]){ // may wanna remove else
                    //swap
                    long long temp = arr2[j];
                    arr2[j] = arr1[i];
                    arr1[i] = temp;
                    j++;
                    i++;
                }
            }
            //Sort the arrays
            quickSort(arr1, 0, n - 1);
            quickSort(arr2, 0, m - 1);
            //Display the arrays
            for(int i = 0; i < n; i++){
                cout << arr1[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < m; i++){
                cout << arr2[i] << " ";
            }
            cout << endl;
        }
        void quickSort2(long long arr[], int n, int low, int high){
            int pivot = arr[0];
            //int low = 1; high = n -1;
            while(low < high){
                if(arr[low] < pivot){
                    low++;
                }
                if(arr[high] > pivot){
                   high--;
                }
                if(arr[high] < pivot && arr[low] > pivot){
                    long long temp = arr[high];
                    arr[high] = arr[low];
                    arr[low] = temp;
                }
            }
            //swap pivot with high
            long long temp = arr[high];
            arr[high] = pivot;
            arr[0] = temp;

            quickSort2(arr, n, 0, high);
            quickSort2(arr, n, low, n - 1);
        }
        void swap1(long long* a, long long* b){
            long long t = *a;
            *a = *b;
        *b = t;
        }

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition1(long long arr[], int low, int high)
{
    long long pivot = arr[high]; // pivot
    int i = (low- 1); // Index of smaller element and indicates
                 // the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap1(&arr[i], &arr[j]);
        }
    }
    swap1(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(long long arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition1(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

};
