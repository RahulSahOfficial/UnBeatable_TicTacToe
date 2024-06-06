#include <bits/stdc++.h>
using namespace std;

class Game{
    
    private:
    int n,filled;
    int yu=0,me=0;
    string winner;
    bool isGameOver;
    vector<vector<string>> grid;

    // For win Loose Detection O(1)
    int cpuLeftDiag,cpuRightDiag,userLeftDiag,userRightDiag; 
    vector<int>cpuCol,cpuRow,userCol,userRow;

    public:
    //Constructors
    Game():Game(3){};
    Game(int nSize){
        n=nSize;
        filled=0;
        winner="";
        isGameOver=false;
        grid.resize(n,vector<string> (n,"0"));

        cpuCol.resize(n,0);
        cpuRow.resize(n,0);
        userRow.resize(n,0);
        userCol.resize(n,0);
        cpuLeftDiag=0;
        cpuRightDiag=0;
        userLeftDiag=0;
        userRightDiag=0;

        //Setting Board
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cnt++;
                grid[i][j]=to_string(cnt);
            }
        }
    }
    void display(){
        cout<<endl<<" -------------"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<" | ";
                if(grid[i][j]=="O" || grid[i][j]=="X")
                    cout<<grid[i][j];
                else
                    cout<<" ";
            }
            cout<<" | "<<endl;
            cout<<" -------------"<<endl;
        }
    }
    void checkState(int x,int y,bool isUser){
        filled++;
        if(isUser){
            userCol[y]++;
            userRow[x]++;
            if(x==y)
                userLeftDiag++;
            if(x+y==n-1)
                userRightDiag++;
            if(userCol[y]==n || userRow[x]==n || userLeftDiag==n || userRightDiag==n){
                isGameOver=true;
                winner="User";
                return;
            }   
        }
        else{
            cpuCol[y]++;
            cpuRow[x]++;
            if(x==y)
                cpuLeftDiag++;
            if(x+y==n-1)
                cpuRightDiag++;
            if(cpuCol[y]==n || cpuRow[x]==n || cpuLeftDiag==n || cpuRightDiag==n){
                isGameOver=true;
                winner="CPU";
                return;
            }   
        }
        if(filled==n*n){
            isGameOver=true;
            winner="DRAW";
        }

    }

    void clearLastMove(int x,int y,bool isUser){
        filled--;
        if(isUser){
            userCol[y]--;
            userRow[x]--;
            if(x==y)
                userLeftDiag--;
            if(x+y==n-1)
                userRightDiag--;
            if(userCol[y]!=n && userRow[x]!=n && userLeftDiag!=n && userRightDiag!=n){
                isGameOver=false;
                winner="";
                return;
            }   
        }
        else{
            cpuCol[y]--;
            cpuRow[x]--;
            if(x==y)
                cpuLeftDiag--;
            if(x+y==n-1)
                cpuRightDiag--;
            if(cpuCol[y]!=n && cpuRow[x]!=n && cpuLeftDiag!=n && cpuRightDiag!=n){
                isGameOver=false;
                winner="";
                return;
            }   
        }
        if(filled!=n*n){
            isGameOver=false;
            winner="";
        }

    }
    void input(){
        cout<<"Your Turn : "<<endl;
        bool inputSuccessful=false;
        int inp,x,y;
        while(!inputSuccessful){
            cout<<"Enter the number : ";
            cin>>inp;
            x=(inp-1)/n;
            y=(inp-1)%n;
            if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==to_string(inp)){
                grid[x][y]="X";
                inputSuccessful=true;
                checkState(x,y,true);
            }
        }
    }
    int tryUserAllMove(int val){
        int score,maxScore=INT_MIN;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                score=0;
                if(grid[x][y]!="X" && grid[x][y]!="O"){
                    string temp=grid[x][y];
                    grid[x][y]="X";
                    checkState(x,y,true);
                    if(isGameOver && winner=="User")
                        score+=val;
                    else
                        score-=tryCPUAllMove(val/2);
                    maxScore=max(maxScore,score);
                    clearLastMove(x,y,true);
                    grid[x][y]=temp;
                }
                
            }
        }
        if(maxScore==INT_MIN)
            maxScore=0;
        return maxScore;
    }
   int tryCPUAllMove(int val){
        int score,maxScore=INT_MIN;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                score=0;
                if(grid[x][y]!="X" && grid[x][y]!="O"){
                    string temp=grid[x][y];
                    grid[x][y]="O";
                    checkState(x,y,false);
                    if(isGameOver && winner=="CPU")
                            score+=val;
                    else
                        score-=tryUserAllMove(val/2);
                    maxScore=max(maxScore,score);
                    clearLastMove(x,y,false);
                    grid[x][y]=temp;
                }
            }
        }
        if(maxScore==INT_MIN)
            maxScore=0;
        return maxScore;
    }
    void getBestCPUMove(){
        cout<<"CPU MOVE"<<endl;
        int bestX,bestY,score,maxScore=INT_MIN,idx,val=1<<30;
        vector<pair<int,int>> poss;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                score=0;
                if(grid[x][y]!="X" && grid[x][y]!="O"){
                    string temp=grid[x][y];
                    grid[x][y]="O";
                    checkState(x,y,false);
                    if(isGameOver && winner=="CPU")
                        score+=val;
                    else
                        score-=tryUserAllMove(val/2);
                    if(score==maxScore)
                        poss.push_back({x,y});
                    else if(score>maxScore){
                        maxScore=score;
                        poss.clear();
                        poss.push_back({x,y});
                    }
                    clearLastMove(x,y,false);
                    grid[x][y]=temp;
                }
            }
        }

        idx=rand()%poss.size();
        bestX=poss[idx].first;
        bestY=poss[idx].second;
        grid[bestX][bestY]="O";
        checkState(bestX,bestY,false);
    }
    void play(){
        while(!isGameOver){
            display();
            if(filled%2==1)
                input();
            else
                getBestCPUMove();
        }
        display();
        if(winner=="DRAW")
            cout<<"MATCH DRAW"<<endl;
        else
            cout<<"Winner : "<<winner;
    }
};

int main()
{
    srand(time(0)); 
    Game* g=new Game();
    g->play();
    return 0;
}
//Modularise and code refactor