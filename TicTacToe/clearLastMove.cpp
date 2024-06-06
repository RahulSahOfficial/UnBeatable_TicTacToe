void Game::clearLastMove(int x, int y, bool isUser)
{
    filled--;
    if (isUser)
    {
        userCol[y]--;
        userRow[x]--;
        if (x == y)
            userLeftDiag--;
        if (x + y == n - 1)
            userRightDiag--;
        if (userCol[y] != n && userRow[x] != n && userLeftDiag != n && userRightDiag != n)
        {
            isGameOver = false;
            winner = "";
            return;
        }
    }
    else
    {
        cpuCol[y]--;
        cpuRow[x]--;
        if (x == y)
            cpuLeftDiag--;
        if (x + y == n - 1)
            cpuRightDiag--;
        if (cpuCol[y] != n && cpuRow[x] != n && cpuLeftDiag != n && cpuRightDiag != n)
        {
            isGameOver = false;
            winner = "";
            return;
        }
    }
    if (filled != n * n)
    {
        isGameOver = false;
        winner = "";
    }
}