// 2024 KAKAO WINTER INTERNSHIP / 가장 많이 받은 선물

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> m;
    int index = 1;
    for(auto i : friends){
        m[i] = index;
        index++;
    }
    vector<vector<int> > adjList = vector<vector<int> >(friends.size()+1, vector<int>(friends.size()+1, 0));
    vector<int> giftVal = vector<int>(friends.size()+1, 0);
    vector<int> result = vector<int>(friends.size()+1, 0);
    
    for(int i=0; i<gifts.size(); i++){
        stringstream ss(gifts[i]);
        string s;
        ss >> s;
        int index1 = m[s];
        ss >> s;
        int index2 = m[s];
        adjList[index1][index2]++;
    }
    
    for(int i=1; i<giftVal.size(); i++){
        int give = 0, recieve = 0;
        for(int j=1; j<giftVal.size(); j++){
            give += adjList[i][j];
            recieve += adjList[j][i];
        }
        giftVal[i] = give-recieve;
    }
    
    for(int i=1; i<adjList.size(); i++){
        for(int j=i+1; j<adjList.size(); j++){
            if(adjList[i][j] > adjList[j][i]){
                result[i]++;
            }
            else if(adjList[i][j] == adjList[j][i]){
                if(giftVal[i] > giftVal[j]){
                    result[i]++;
                }
                else if(giftVal[i] < giftVal[j]){
                    result[j]++;
                }
            }
            else if(adjList[i][j] < adjList[j][i]){
                result[j]++;
            }
        }
    }
        
    for(auto i : result){
        answer = max(i, answer);
    }
    
    return answer;
}