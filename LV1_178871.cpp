// 연습문제 / 달리기 경주


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m;
    answer = players;
    for(int i=0; i<players.size(); i++){
        m[players[i]] = i;
    }
    for(int i=0; i<callings.size(); i++){
        int index = m[callings[i]];
        m[answer[index]]--;
        m[answer[index-1]]++;
        string temp = answer[index];
        answer[index] = answer[index-1];
        answer[index-1] = temp;
    }
    return answer;
}