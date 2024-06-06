void Game::checkState(int x, int y, bool isUser)
{
    filled++;
    if (isUser)
    {
        userCol[y]++;
        userRow[x]++;
        if (x == y)
            userLeftDiag++;
        if (x + y == n - 1)
            userRightDiag++;
        if (userCol[y] == n || userRow[x] == n || userLeftDiag == n || userRightDiag == n)
        {
            isGameOver = true;
            winner = "User";
            return;
        }
    }
    else
    {
        cpuCol[y]++;
        cpuRow[x]++;
        if (x == y)
            cpuLeftDiag++;
        if (x + y == n - 1)
            cpuRightDiag++;
        if (cpuCol[y] == n || cpuRow[x] == n || cpuLeftDiag == n || cpuRightDiag == n)
        {
            isGameOver = true;
            winner = "CPU";
            return;
        }
    }
    if (filled == n * n)
    {
        isGameOver = true;
        winner = "DRAW";
    }
}