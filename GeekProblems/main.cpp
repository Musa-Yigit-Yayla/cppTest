#include <iostream>
//#include "Solution.cpp"
#include "Permutation.cpp"
#include "MathFunctions.cpp"
#include "HowManyLaptops.cpp"
#include <vector>
#include <string>
using namespace std;

int main(){
    /*//Solution sol;
    Permutation perm;
    vector<string> stringVector;

    stringVector = perm.find_permutation("ABCDE");
    for(size_t i = 0; i < stringVector.size(); i++){
        string curr = stringVector.at(i);
        cout << curr << endl;
    }
    cout << MathFunctions::trailingZeroesInFactorial(251);
    MathFunctions::printAllDivisors(100);
    vector<int> vec = MathFunctions::quadraticRoots(1, 4, 4);
    cout << vec.at(0);
    //std::cout << sol.maxGcd(4);*/
    HowManyLaptops hwl;
    int start[]{2, 1, 1, 1, 4, 2};
    int ending[]{3, 2, 2, 2, 5, 4};
    cout << hwl.minLaptops(6, start, ending);
    return 0;
}
