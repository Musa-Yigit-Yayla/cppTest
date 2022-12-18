

/*class Solution{
private:
    int primes[14] = {2, 3, 7, 13, 17, 31, 37, 41, 43, 47, 71, 73, 79, 97};
public:
    long long maxGcd(int N) {


        int* nums1 = new int[4];
        nums1[0] = N;
        nums1[1] = N - 1;
        nums1[2] = N - 2;
        nums1[3] = N - 3;

        int* nums2 = new int[4];
        nums1[0] = N;
        nums1[1] = N - 1;
        nums1[2] = N - 2;
        nums1[3] = N;

        long long lcm1 =  findLCM(nums1);
        long long lcm2 = findLCM(nums2);

        delete nums1;
        delete nums2;

        if(lcm1 > lcm2){
            return lcm1;
        }
        else{
            return lcm2;
        }
    }

    long long findLCM(int* numbers1){
        //find the lcm
        long long multiplication1 = 1;
        int divisor = primes[0];
        int divisorIndex = 0;

        while(!isAllNums1(numbers1)){
                int divisionCount = 0;
            for(int i = 0; i < 4; i++){
                if(numbers1[i] % divisor == 0){
                    numbers1[i] / divisor;
                    divisionCount++;
                }
            }
            if(divisionCount == 0){
                //switch to the next divisor
                divisor = primes[++divisorIndex];
            }
            else{
                //cout << divisor << "|" << numbers1[0] << " " << numbers1[1] << " " << numbers2[2] << " " << numbers3[3] << endl;
                multiplication1 *= divisor;
            }
        }
        return multiplication1;
    }
    //returns true if all nums are 1 in the given 4 digit array
    bool isAllNums1(int* arr){
        for(int i = 0; i < 4; i++){
            if(*arr != 1){
                return false;
            }
            arr++;
        }
        return true;
    }
};
*/
