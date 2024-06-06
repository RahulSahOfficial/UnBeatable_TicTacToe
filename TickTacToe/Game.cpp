#include <bits/stdc++.h>
using namespace std;
class Game
{

private:
    int n, filled;
    bool userFirst;
    string winner;
    bool isGameOver;
    vector<vector<string>> grid;

    // For win Loose Detection O(1)
    int cpuLeftDiag, cpuRightDiag, userLeftDiag, userRightDiag;
    vector<int> cpuCol, cpuRow, userCol, userRow;

public:
    // Constructors
    Game() : Game(3,false){};
    Game(bool userPlayFirst) : Game(3,userPlayFirst){};
    Game(int n) : Game(n,false){};
    Game(int nSize,bool userPlayFirst)
    {
        n = nSize;
        filled = 0;
        winner = "";
        userFirst=userPlayFirst;
        isGameOver = false;
        grid.resize(n, vector<string>(n, "0"));

        cpuCol.resize(n, 0);
        cpuRow.resize(n, 0);
        userRow.resize(n, 0);
        userCol.resize(n, 0);
        cpuLeftDiag = 0;
        cpuRightDiag = 0;
        userLeftDiag = 0;
        userRightDiag = 0;

        // Setting Board
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cnt++;
                grid[i][j] = to_string(cnt);
            }
        }
    }
    void display();
    void checkState(int, int, bool);
    void clearLastMove(int, int, bool);
    void input();
    int tryUserAllMove(int);
    int tryCPUAllMove(int);
    void getBestCPUMove();
    void play();
};


#include "display.cpp"
#include "checkState.cpp"
#include "clearLastMove.cpp"
#include "input.cpp"
#include "tryUserAllMove.cpp"
#include "tryCPUAllMove.cpp"
#include "getBestCPUMove.cpp"
#include "play.cpp"