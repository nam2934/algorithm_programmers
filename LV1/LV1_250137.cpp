// [PCCP 기출문제] 1번 / 붕대 감기


#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int attacksIndex = 0;
    int time = 1;
    int cont = 0;
    int initHealth = health;
    while(1){
        if(attacksIndex == attacks.size()) break;
        if(attacks[attacksIndex][0] == time){
            health -= attacks[attacksIndex][1];
            attacksIndex++;    
            cont = 0;
        }
        else{
            health += bandage[1];
            cont++;
            if(cont == bandage[0]){
                health += bandage[2];
                cont = 0;
            }
        }
        if(health > initHealth) health = initHealth;
        if(health <= 0){
            answer = -1;
            return answer;
        }
        time++;
    }
    answer = health;
    return answer;
}