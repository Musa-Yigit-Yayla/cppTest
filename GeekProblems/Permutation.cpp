#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Permutation{
private:
    vector<string> allPermutations;
    string originalString;
    int stringLength;
public:
    vector<string>find_permutation(string s){
        stringLength = s.length();
        originalString = s;
        vector<int> deletionIndexes;
        string emptyString = "";
        find_permutation_helper(emptyString, deletionIndexes);
        return allPermutations;
    }
    void find_permutation_helper(string s, vector<int> deletionIndexes){
        if(static_cast<int>(s.length()) == stringLength){
            //current permutation has been achieved
            //add it to vector
            allPermutations.push_back(s);
            return;
        }
        //Might be problematic

        int x;
        do{
            x = rand() % stringLength;
        }while(contains(x, deletionIndexes));
        deletionIndexes.push_back(x);
        s += originalString.at(x);
        //Recursive step
        find_permutation_helper(s, deletionIndexes);

    }

    static bool contains(int x, vector<int> arr){
        for(size_t i = 0; i < arr.size(); i++){
            if(arr.at(i) == x){
                return true;
            }
        }
        return false;
    }
};
