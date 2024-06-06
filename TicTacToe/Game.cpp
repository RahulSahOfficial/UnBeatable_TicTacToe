#include <bits/stdc++.h>
using namespace std;
class Game
{

private:
    int n, filled;
    bool userFirst;
    string winner,gameLine;
    bool isGameOver;
    vector<vector<char>> grid;

    // For win Loose Detection O(1)
    int cpuLeftDiag, cpuRightDiag, userLeftDiag, userRightDiag;
    vector<int> cpuCol, cpuRow, userCol, userRow;

public:
    // Constructor
    Game(int nSize=3,bool userPlayFirst=false)
    {
        n = nSize;
        filled = 0;
        winner = "";
        userFirst=userPlayFirst;
        isGameOver = false;
        grid.resize(n, vector<char>(n, ' '));

        cpuCol.resize(n, 0);
        cpuRow.resize(n, 0);
        userRow.resize(n, 0);
        userCol.resize(n, 0);
        cpuLeftDiag = 0;
        cpuRightDiag = 0;
        userLeftDiag = 0;
        userRightDiag = 0;

        //generating Game Line
        gameLine=" ";
        for(int i=0;i<3*n+n+1;i++)
            gameLine+="-";

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