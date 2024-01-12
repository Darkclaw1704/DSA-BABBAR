#include <iostream>
using namespace std;

int countDistinctWays(int nStairs) {
    if (nStairs==0){
        return 1;
    }
    if(nStairs<0){
        return 0;
    }

    int answer = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);

    return answer;
}

