// [PCCP 기출문제] 2번 / 석유 시추


#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > visited;
vector<vector<pair<int, int> > > result;
stack<pair<int, int> > st;

int W, H, count;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void DFS(int y, int x, vector<vector<int>>& land){
    visited[y][x] = true;
    count++;
    st.push(make_pair(y, x));
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < W && ny < H){
            if(!visited[ny][nx] && land[ny][nx] == 1){
                DFS(ny, nx, land);    
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    H = land.size();
    W = land[0].size();
    result.assign(H, vector<pair<int, int> >(W, make_pair(0, 0)));
    visited.assign(H, vector<int>(W, false));
                   
    int lcount = 0;             
    for(int i=0; i<W; i++){
        for(int j=0; j<H; j++){
            if(land[j][i] == 1 && !visited[j][i]){
                count = 0;
                DFS(j, i, land);
                lcount++;
                while(!st.empty()){
                    pair<int, int> p = st.top();
                    result[p.first][p.second].second = count;
                    result[p.first][p.second].first = lcount;
                    st.pop();
                }
            }
        }
    }
    
    for(int i=0; i<W; i++){
        bool flag = false;
        int sumVal = 0;
        vector<int> lcountList(lcount+1, 0);
        for(int j=0; j<H; j++){
            if(visited[j][i]){
                if(!flag && !lcountList[result[j][i].first]) sumVal += result[j][i].second;
                lcountList[result[j][i].first]++;
                flag = true;
            }
            else flag = false;
        }
        cout << sumVal << endl;
        answer = max(answer, sumVal);
    }             
                   
    return answer;
}