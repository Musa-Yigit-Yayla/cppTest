#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <random>
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
        int deletionIndexes[stringLength];
        int deletionIndexSize = 0;
        string emptyString = "";
        srand(time(NULL));
        find_permutation_helper(emptyString, deletionIndexes, deletionIndexSize);
        return allPermutations;
    }
    void find_permutation_helper(string s, int deletionIndexes[], int deletionIndexSize){
        if(static_cast<int>(s.length()) == stringLength){
            //current permutation has been achieved
            //add it to vector
            allPermutations.push_back(s);
            return;
        }
        //Might be problematic

        /*int x;
        do{
            x = rand() % (originalString.length());
        }while(contains(x, deletionIndexes, deletionIndexSize));
        deletionIndexes[deletionIndexSize] = x;
        s += originalString.at(x);*/
        //Recursive step
        int boundary = static_cast<int>(-s.length());
        boundary += stringLength;
        for(int i = 0; i < boundary; i++){ // switch to <
            string sCopy = s;
            int x;
            do{
                x = rand() % (originalString.length());
            }while(contains(x, deletionIndexes, deletionIndexSize));

            //copy the current array
            int newDeletionIndex[stringLength];
            copyNewDeletionIndexes(newDeletionIndex, deletionIndexes, stringLength);
            newDeletionIndex[deletionIndexSize] = x;
            sCopy += originalString.at(x);
            find_permutation_helper(sCopy, newDeletionIndex, deletionIndexSize + 1);
        }
    }

    static bool contains(int x, int arr[], int deletionIndexesSize){
        for(int i = 0; i < deletionIndexesSize; i++){
            if(arr[i] == x){
                return true;
            }
        }
        return false;
    }
    //copy a new of the given array
    static void copyNewDeletionIndexes(int copyDeletionIndexes[] ,const int deletionIndexes[], int length){
        //int copyDeletionIndexes[stringLength];
        for(int i = 0; i < length; i++){
            copyDeletionIndexes[i] = deletionIndexes[i];
        }
        //return copyDeletionIndexes;
    }
};
