#include <iostream>
//#include "Solution.cpp"
#include "Permutation.cpp"
#include "MathFunctions.cpp"
#include "HowManyLaptops.cpp"
#include "MergeWithoutSpace.cpp"
#include "MinimizeStudents.cpp"
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
    //HowManyLaptops hwl;
    /*long long start[]{13, 21, 25, 25, 25, 28, 30, 30, 34, 35, 36, 39, 49, 49,};
    long long ending[]{10, 29};
    //cout << hwl.minLaptops(6, start, ending);
    MergeWithoutSpace mws;
    mws.builtInMerge(start, ending, 14 ,2);*/
    MinimizeStudents ms;

    int n = 6;
    int H[]{9, 1, 2, 3, 1, 5};
    cout << ms.removeStudent(H, n);
    return 0;
}
