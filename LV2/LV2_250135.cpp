// [PCCP 기출문제] 3번 / 아날로그 시계

#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int startTime = h1*3600 + m1*60 + s1;
    int endTime = h2*3600 + m2*60 + s2;
    int interval = endTime - startTime;
    int s = s1*6*120;
    int m = m1*6*120 + s1*12;
    int h = h1*30*120 + m1*60 + s1;
    if(startTime == 0 || startTime == 3600*12) answer++;
    for(int i=1; i<=interval; i++){
        int prevS = s, prevM = m, prevH = h;
        s = s+6*120;
        m = m + 12;
        h = h + 1;
        if(s >= m && prevS < prevM) answer++;
        if(s >= h && prevS < prevH) answer++;   
        if(s >= 360*120) s -= 360*120;
        if(m >= 360*120) m -= 360*120;
        if(h >= 360*120) h -= 360*120; 
        if(s == m && s == h) answer--;
    }
    return answer;
}