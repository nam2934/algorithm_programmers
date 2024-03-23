// [PCCE 기출문제] 9번 / 이웃한 칸

#include <string>
#include <vector>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    string s = board[h][w];
    for(int i=0; i<4; i++){
        int ny = h + dy[i];
        int nx = w + dx[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(!s.compare(board[ny][nx])) answer++;
        }
    }
    return answer;
}