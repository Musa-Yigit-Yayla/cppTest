#include <algorithm>
#include <cmath>
using namespace std;

class HowManyLaptops{
public:
    int minLaptops(int N, int start[], int ending[]) {
        // Code here
        //Find the maximum number of laptops used at any time
        //Do this by calculating the differences between start and ending arrays
        //Çakışan zaman dilimlerini bulmaya çalış
        int firstStart = start[0]; //minimum of the start
        int lastEnd = ending[0]; // maximum of the end
        int minimumLaptopCount = 0;
        for(int i = 1; i < N - 1; i++){
            int startCurr = start[i];
            int endCurr = ending[i];
            int fs1 = firstStart; // for debugging //PROBLEM HERE

            if(startCurr < firstStart){
                firstStart = startCurr;
                fs1 = firstStart;

            }
            if(endCurr > lastEnd){
                lastEnd = endCurr;
            }
        }
        /*while(firstStart <= lastEnd){ // change to <
            int currLaptopCount = 0;

            //check each array element
            for(int i = 0; i < N; i++){
                int fs = firstStart, ls = lastEnd;
                int currStart = start[i];
                int currEnd = ending[N - i - 1];
                if(firstStart < currStart && lastEnd > currEnd){
                    currLaptopCount++;
                }
            }
            if(currLaptopCount > minimumLaptopCount){
                minimumLaptopCount = currLaptopCount;
            }
            firstStart++;
            lastEnd--; // maybe remove
        }*/
        int max1 = mostFrequent(start, N, 1);
        int max2 = mostFrequent(ending, N, 0);
        return max(max1, max2);

        //return minimumLaptopCount;
    }
    //returns the number of max occurences of any digit in the array
    int mostFrequent(int arr[], int n, bool isStart){
        // Sort the array
        sort(arr, arr + n);

        if(!isStart)
            int frequentDigit = mostFrequentDigit(arr, n);

        // Find the max frequency using linear traversal
        int max_count = 1, res = arr[0], curr_count = 1;
        for (int i = 1; i < n; i++) {

            if (arr[i] == arr[i - 1] || arr[i] < arr[i - 1] && (!isStart && arr[i] > arr[i - 1]))
                curr_count++;
            else
                curr_count = 1;

            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }

        }

        return max_count;
    }
    int mostFrequentDigit(int arr[], int n){
        // Sort the array
        sort(arr, arr + n);

        // Find the max frequency using linear traversal
        int max_count = 1, res = arr[0], curr_count = 1;
        for (int i = 1; i < n; i++) {

            if (arr[i] == arr[i - 1] || arr[i] < arr[i - 1])
                curr_count++;
            else
                curr_count = 1;

            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }

        }

        return res;
    }
};
