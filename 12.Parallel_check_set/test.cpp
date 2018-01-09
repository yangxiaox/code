/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月04日 星期六 16时12分31秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void merge(vector<vector<char>>& board, int a, int b) {
        if (0 > a || a > board.size() || 0 > b || b > board[a].size()) return ;
        if (board[a][b] != 'O') return ;
        board[a][b] = 'Q';
        for (int i = 0; i < 4; ++i) {
            merge(board, a + dir[i][0], b + dir[i][1]);
        }
        return ;
    }
    
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                merge(board, i, j);
                if (i != 0 && i != (board.size() - 1) && j == 0) j = board[i].size() - 2; 
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Q') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {
    return 0;
}
