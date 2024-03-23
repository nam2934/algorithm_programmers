// 연습문제 / 공원 산책


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int H = park.size();
    int W = park[0].size();
    pair<int, int> start;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(park[i][j] == 'S'){
                start.first = i;
                start.second = j;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++){
        char op = routes[i][0];
        int move = int(routes[i][2]) - '0';
        bool flag = true;
        if(op == 'S'){
            if(start.first + move < H){
                for(int i=1; i<=move; i++){
                    if(park[start.first+i][start.second] != 'X') continue;
                    else flag = false;
                }                
            }
            else flag = false;
            if(flag){
                start.first = start.first + move;
            }
        }
        else if(op == 'N'){
            if(start.first - move >= 0){
                for(int i=1; i<=move; i++){
                    if(park[start.first-i][start.second] != 'X') continue;
                    else flag = false;
                }                
            }
            else flag = false;
            if(flag){
                start.first = start.first - move;
            }
        }      
        else if(op == 'E'){
            if(start.second + move < W){
                for(int i=1; i<=move; i++){
                    if(park[start.first][start.second+i] != 'X') continue;
                    else flag = false;
                }                
            }
            else flag = false;
            if(flag){
                start.second = start.second + move;
            }
        }  
        else if(op == 'W'){
            if(start.second - move >= 0){
                for(int i=1; i<=move; i++){
                    if(park[start.first][start.second-i] != 'X') continue;
                    else flag = false;
                }                
            }
            else flag = false;
            if(flag){
                start.second = start.second - move;
            }
        }          
    }
    answer.push_back(start.first);
    answer.push_back(start.second);
    return answer;
}