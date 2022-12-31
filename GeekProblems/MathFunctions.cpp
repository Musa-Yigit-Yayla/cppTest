//Some math functions stored inside the class
#include <cmath>
#include <vector>
#include <iostream>
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
    int exactly3Divisors(int N){
       //check each number up to N which has its square root as prime
       int counter = 0;
       for(int i = 1; i <= N; i++){
            if(isPrime(sqrt(i))){
                counter++;
            }
       }
       return counter;
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
    static void printAllDivisors(int n){
        //print all divisors in sorted order
        vector<int> divisors;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                int div1 = n / i;
                int div2 = i;
                divisors.push_back(div1);
                divisors.push_back(div2);
            }
        }
        int divs[divisors.size()];


        for(int i = 0; i < divisors.size(); i++){
            divs[i] = divisors.at(i);
        }
        //sort the list
        for(int i = 0; i < sizeof(divs) / sizeof(int); i++){
            int num = divs[i];
            for(int j = i + 1; j < sizeof(divs) / sizeof(int) - i; j++){
                if(num > divs[j]){
                    int temp = divs[j];
                    divs[j] = num;
                    divs[i] = temp;
                }
            }
        }
        cout << endl;
        //print the list
        for(int i = 0; i < sizeof(divs) / sizeof(int); i++){
            cout << divs[i] << " ";
        }
        cout << endl;
    }
    static vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        vector<int> solutions;
        int sol1, sol2;

        sol1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        sol2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        solutions.push_back(max(sol1, sol2));
        solutions.push_back(min(sol1, sol2));

        return solutions;
    }
    bool isPrime(int n)
    {

        if(n <= 1){
            return false;
        }
        double boundary = n / 2.0;
        for(double i = 2.0; i <= boundary; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
        //Your code here
    }
    int modInverse(int a, int m){
        int result = -1;
        for(int i = 1; i < m; i++){
            if((a * i) % m == 1){
                result = i;
            }
        }
        return result;
    }
};
