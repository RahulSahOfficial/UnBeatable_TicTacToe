int Game::tryUserAllMove(int val)
{
    int score, maxScore = INT_MIN;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            score = 0;
            if (grid[x][y] != 'X' && grid[x][y] != 'O')
            {
                char temp = grid[x][y];
                grid[x][y] = 'X';
                checkState(x, y, true);
                if (isGameOver && winner == "User")
                    score += val;
                else
                    score -= tryCPUAllMove(val / 2);
                maxScore = max(maxScore, score);
                clearLastMove(x, y, true);
                grid[x][y] = temp;
            }
        }
    }
    if (maxScore == INT_MIN)
        maxScore = 0;
    return maxScore;
}