//Some math functions stored inside the class
#include <cmath>

using namespace std;

class MathFunctions{
public:

    //Theta(logn)
    static int trailingZeroesInFactorial(int n){
        int c = 0;
        int counter = 1;
        int tempN = n;
        while(tempN > 0){
            c += floor(n / pow(5, counter));
            tempN /= 5;
            counter++;
        }
        return c;
    }
    bool isPrime(int n)
    {

        if(n <= 1){
            return false;
        }
        double boundary = n / 2.0;
        for(int i = 2; i <= boundary; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
        //Your code here
    }
    //Find nth term of geometric series A and B are first two terms
    double termOfGP(int A,int B,int N)
    {
        double r = (B * 1.0) / (A * 1.0);
        double result = A * 1.0;
        while(N > 1){
            result *= r;
            N--;
        }
        return result;
    }
    //Comes in pack
    int exactly3Divisors(int N)
    {
        //Your code here
        //Has to be non prime
        int divisorCount = 0;
        for(int i = 4; i <= N; i++){
            if(checkExact3Divisors(i)){
                divisorCount++;
            }
        }
        return divisorCount;
    }
    bool checkExact3Divisors(int n){
        int divCount = 2;
        for(int i = 2; i < n; i++){
            if(n % i == 0){
                divCount++;
            }
            if(divCount > 3){
                break;
            }
        }
        return divCount == 3;
    }
    //Comes in pack
};
