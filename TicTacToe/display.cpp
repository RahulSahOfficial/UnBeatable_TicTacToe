void Game::display()
{
    cout<<endl<<gameLine<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " | "<< grid[i][j];
        }
        cout << " | " << endl;
        cout<<gameLine<<endl;
    }
}