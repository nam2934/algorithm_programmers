// 2023 KAKAO BLIND RECRUITMENT / 택배 배달과 수거하기

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void process(vector<int>& target, int cap){
    int index = target.size()-1;
    if(index == -1) return;
    while(target.size() != 0 && target[index] == 0){
        target.pop_back();
        index--;
    }
    while(index >= 0 && cap > 0){
        if(target[index] == 0){
            index--;
            continue;
        }
        target[index]--;
        cap--;
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    while(deliveries.size() > 0 || pickups.size() > 0){
        process(deliveries, cap);
        process(pickups, cap);
        answer += 2*max(deliveries.size(), pickups.size());
    }
    return answer;
}