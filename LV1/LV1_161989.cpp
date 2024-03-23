// 연습문제 / 덧칠하기

#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int iter = section[0];
    for(int i=0; i<section.size(); i++){
        if(iter > section[i]){
            continue;
        }
        if(iter <= section[i]){
            iter = section[i];
            answer++;
            iter += m;
        }
    }
    return answer;
}