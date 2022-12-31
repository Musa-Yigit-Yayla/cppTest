
using namespace std;

class HowManyLaptops{
public:
    int minLaptops(int N, int start[], int ending[]) {
        // Code here
        //Find the maximum number of laptops used at any time
        //Do this by calculating the differences between start and ending arrays
        //Çakışan zaman dilimlerini bulmaya çalış
        int* firstStart = &start[0]; //minimum of the start
        int* lastEnd = &ending[0]; // maximum of the end
        int minimumLaptopCount = 0;
        for(int i = 1; i < N - 1; i++){
            int startCurr = start[i];
            int endCurr = ending[i];
            int fs1 = *firstStart; // for debugging //PROBLEM HERE

            if(startCurr < *firstStart){
                firstStart = &startCurr;
                fs1 = *firstStart;

            }
            if(endCurr > *lastEnd){
                lastEnd = &endCurr;
            }
        }
        while(*firstStart <= *lastEnd){ // change to <
            int currLaptopCount = 0;

            //check each array element
            for(int i = 0; i < N; i++){
                int fs = *firstStart, ls = *lastEnd;
                int currStart = start[i];
                int currEnd = ending[i];
                if(*firstStart >= currStart && *lastEnd >= currEnd){
                    currLaptopCount++;
                }
            }
            if(currLaptopCount > minimumLaptopCount){
                minimumLaptopCount = currLaptopCount;
            }
            *firstStart++;
        }
        return minimumLaptopCount;
    }
};
