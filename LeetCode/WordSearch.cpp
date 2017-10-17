//
// Created by Kristen Wong on 10/12/17.
//

// ----- TIME COMPLEXITY -----
// The time complexity is O(4^n) where n is the length of the word that you are searching for.
// This is because worst case, we must search in 4 directions for per letter possibility for
//  the entire length of the word.

#include <iostream>
#include <vector>
using namespace std;

class WordSearchSolution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0] && DFS(board, i , j, word, 0)) return true;
                }
            }
        return false;
        }

private:
    bool DFS(vector<vector<char>> &board, int i, int j, string word, int index) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false; // return false if indices are out of bounds
        if (board[i][j] != word[index]) return false;// return false if the character doesn't match the target
        if (index == word.length() - 1) return true;

        index ++;
        char temp = board[i][j];
        board[i][j] = '?'; // put random character to prevent overlap searches
        bool valid = DFS(board, i + 1, j, word, index) ||
                     DFS(board, i - 1, j, word, index) ||
                     DFS(board, i, j + 1, word, index) ||
                     DFS(board, i, j - 1, word, index);
        board[i][j] = temp; // put original character back
        return valid;
    }
};