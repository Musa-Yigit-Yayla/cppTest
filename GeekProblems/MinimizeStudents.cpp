#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class MinimizeStudents{
private:
    vector<vector<int>> subsequences;
public:
    int minimizeStudent(int arr[], int n){
        int result = 0;
        for(int i = 0; i < n - 1; i++){
            int curr = arr[i];
            int next = arr[i + 1];
            if(curr > next){
               //remove next element decrement i to preserve the checking for the current index
                //removeElt(arr, i + 1, n);
                i--;
                result++;
            }
        }
        return result;
    }
    int removeStudent(int heights[], int n){
        int result;
        //Find all subsequences
        this->findSubsequences();
        //Remove non increasing subsequences
        bool x = this->isIncreasingVector(); // clear the non increasing ones
        this->subsequences.resize();
        //find the lengthiest vector
        int maxSize = this->subsequences.at(0).size();
        for(İnt j = 1; j < this->subsequences.size(); j++){
            int currSize = this->subsequences.at(i).size();
            if(currSize > maxSize){
                maxSize = currSize;
            }
        }
        return n - maxSize; // no of students to be removed

    }

    void findSubsequences(int arr[], int index, vector<int> &subarr,int n){
        // Print the subsequence when reach
        // the leaf of recursion tree
        if (index == n){

            this->subsequences.push_back(subarr);
            return;
        }
        else{
        //pick the current index into the subsequence.
            subarr.push_back(arr[index]);


            findSubsequences(arr, index + 1, subarr,n);


            subarr.pop_back();

        //not picking the element into the subsequence.
            findSubsequences(arr, index + 1, subarr,n);
        }

    }
    //Clear the non increasing ones will return true if anything exists
    bool isIncreasingVector(vector<int> &vec){
        bool returnVal = false;
        for(int i = 0; i < vec.size(); i++){
            vector<int> currentVec = this->findSubsequences().at(i);
            int prev = currentVec.at(0);
            int curr;
            if(vec.size() <= 1){
                continue;
            }

            for(int j = 0; j < currentVec.size(); j++){
                curr = currentVec.at(j);
                if(curr < prev){
                    //subsequence doesn't work remove the subsequence at the subsequences vector
                    this->subsequences.erase(i);
                    i--;
                    break;
                }
                else if(j == currentVec.size() - 1){
                    //A vector with increasing order exists set to true
                    returnVal = true;
                }
                prev = curr;
            }
        }
        return returnVal;
    }
    void removeElt(int* arr, int index, int n){
        while(index < n - 1){
            arr[index] = arr[index + 1];
            index++;
        }
    }
};
