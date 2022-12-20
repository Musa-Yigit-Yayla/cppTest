#include <iostream>
#include "Solution.cpp"
#include "Permutation.cpp"
#include <vector>
#include <string>
using namespace std;

int main(){
    Solution sol;
    Permutation perm;
    vector<string> stringVector;

    stringVector = perm.find_permutation("ABCD");
    for(size_t i = 0; i < stringVector.size(); i++){
        cout << stringVector.pop_back() << endl;
    }
    //std::cout << sol.maxGcd(4);
    return 0;
}
