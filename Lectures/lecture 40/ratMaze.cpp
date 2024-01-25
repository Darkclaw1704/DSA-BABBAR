#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &maze, int n, vector<vector<int>> visited, int x, int y){
    if((x>=0 && x<n) && (y>=0 && y<n) && (maze[x][y] == 1) && (visited[x][y] == 0)){
        return true;
    }
    return false;
}

void solve(vector<vector<int>> &maze, int n, vector<vector<int>> visited, int x, int y,string path ,vector<string> &answer){
    if(x == n-1 && y == n-1){
        answer.push_back(path);
        return;
    }

    visited[x][y] = 1;

    int nextx = x +1;
    int nexty = y ;
    if(isSafe(maze, n , visited, nextx, nexty)){
        path.push_back('D');
        solve(maze,n,visited, nextx, nexty, path, answer);
        path.pop_back();
    }

    nextx = x;
    nexty = y - 1 ;
    if(isSafe(maze, n , visited, nextx, nexty)){
        path.push_back('L');
        solve(maze,n,visited, nextx, nexty, path, answer);
        path.pop_back();
    }

    nextx = x;
    nexty = y +1  ;
    if(isSafe(maze, n , visited, nextx, nexty)){
        path.push_back('R');
        solve(maze,n,visited, nextx, nexty, path, answer);
        path.pop_back();
    }

    nextx = x - 1;
    nexty = y  ;
    if(isSafe(maze, n , visited, nextx, nexty)){
        path.push_back('U');
        solve(maze,n,visited, nextx, nexty, path, answer);
        path.pop_back();
    }

    visited[x][y] = 0;

}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> answer;

    if(m[0][0] == 0){
        return answer;
    }

    string path = "";
    int x = 0;
    int y = 0;

    vector<vector<int>> visited;

    for(int i = 0; i<n; i++){
        vector<int> row;
        for(int j = 0; j<n; j++){
            row.push_back(0);
        }
        visited.push_back(row);
    }

    solve(m,n, visited, x, y, path, answer);

    return answer;

}