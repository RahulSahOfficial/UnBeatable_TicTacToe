int Game::tryCPUAllMove(int val)
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
                grid[x][y] = 'O';
                checkState(x, y, false);
                if (isGameOver && winner == "CPU")
                    score += val;
                else
                    score -= tryUserAllMove(val / 2);
                maxScore = max(maxScore, score);
                clearLastMove(x, y, false);
                grid[x][y] = temp;
            }
        }
    }
    // if (maxScore == INT_MIN)
    //     maxScore = 0;
    return maxScore;
}