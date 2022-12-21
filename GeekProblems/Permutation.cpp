#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>

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

        //There might be multiples coming from the helper method, so clean the vector before sending it
        vector<string> cleanVector;
        for(size_t i = 0; i < allPermutations.size(); i++){
            string curr = allPermutations.at(i);
            if(find(cleanVector.begin(), cleanVector.end(), curr) == cleanVector.end()){
                //element not found
                cleanVector.push_back(curr);
            }
        }


        return cleanVector;
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
            int x; // new char adding index
            int newDeletionIndex[stringLength];
            copyNewDeletionIndexes(newDeletionIndex, deletionIndexes, s.length()); // change to stringLength
            /*for(int i = 0; i < originalString.length(); i++){
                if(!contains(i, newDeletionIndex, deletionIndexSize)){
                    x = i;
                    break;
                }
            }*/
            do{
                x = rand() % (originalString.length());
            }while(contains(x, newDeletionIndex, deletionIndexSize));
            //copy the current array
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
    void copyNewDeletionIndexes(int copyDeletionIndexes[] ,const int deletionIndexes[], int length){
        //int copyDeletionIndexes[stringLength];
        for(int i = 0; i < length; i++){
            copyDeletionIndexes[i] = deletionIndexes[i];
        }
        for(int j = length; j < stringLength; j++){
            copyDeletionIndexes[j] = -1;
        }
        //return copyDeletionIndexes;
    }
};
