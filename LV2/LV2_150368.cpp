// 2023 KAKAO BLIND RECRUITMENT / 이모티콘 할인행사

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double discount[4] = {0.6, 0.7, 0.8, 0.9};
vector<double> permutationArr;
int resultPlus = 0;
int resultCost = 0;

void permutation(int cnt, int size, vector<vector<int> >& users, vector<int>& emoticons){
    if(cnt == size){
        int plus = 0;
        int cost = 0;
        for(auto user : users){
            int temp = 0;
            for(int i=0; i<permutationArr.size(); i++){
                if(100-permutationArr[i]*100 >= user[0]){
                    temp += emoticons[i]*permutationArr[i];
                }
                else continue;
            }
            if(temp >= user[1]){
                plus++;
            }
            else cost += temp;
        }
        if(resultPlus < plus){
            resultPlus = plus;
            resultCost = cost;
        }
        else if(resultPlus == plus){
            resultCost = max(resultCost, cost);
        }
        return;
    }
    for(int i=0; i<4; i++){
        permutationArr[cnt] = discount[i];
        permutation(cnt+1, size, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    permutationArr = vector<double>(emoticons.size());
    permutation(0, emoticons.size(), users, emoticons);
    
    answer.push_back(resultPlus);
    answer.push_back(resultCost);
    
    return answer;
}