//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>
using namespace std;

// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in
// nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.
// And we defined a friend circle is a group of students who are direct or indirect friends.

// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith
// and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend
// circles among all the students.

class FriendCirclesSolution {
public:
    void depthFirst(vector<vector<int>> M, bool arr[], int i){
        for (int j = 0; j < M.size(); j ++ ){
            if(M[i][j] == 1 && !arr[j]){
                arr[j] = true;
                depthFirst(M, arr, j);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& M) {
        int friendCircles = 0;
        int length = M.size();
        bool* arr = new bool[length] {false};

        for (int i = 0; i < length; i ++){
            if (arr[i] == 0){
                friendCircles ++;
                depthFirst(M, arr, i);
            }
        }
        return friendCircles;
    }


};