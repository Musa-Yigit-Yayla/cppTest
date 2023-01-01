#include <iostream>
//#include "Solution.cpp"
#include "Permutation.cpp"
#include "MathFunctions.cpp"
#include "HowManyLaptops.cpp"
#include "MergeWithoutSpace.cpp"
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
    long long start[]{1,3,5,7};
    long long ending[]{0,2,6,8,9};
    //cout << hwl.minLaptops(6, start, ending);
    MergeWithoutSpace mws;
    mws.builtInMerge(start, ending, 4 ,5);
    return 0;
}
