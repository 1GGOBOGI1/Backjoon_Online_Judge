#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string.h>
using namespace std;

vector<vector<int>> S;
bool check[21] = {false};

int getAbility(vector<int> teamA, vector<int> teamB)
{
    int totalAbility = 0;
    int teamA_ability = 0, teamB_ability = 0;

    for (int i = 0; i < teamA.size() -1; i++)
    {
        for (int j = i - 1; j < teamA.size(); j++)
        {
            teamA_ability = teamA_ability+ S[teamA[i]][teamA[j]] + S[teamA[j]][teamA[i]];
            teamB_ability = teamB_ability+ S[teamB[i]][teamB[j]] + S[teamB[j]][teamB[i]];
        }
    }
    totalAbility = abs(teamA_ability - teamB_ability);

    return totalAbility;
}

void DFS(int playerNumber, int totalPlayer, int N, int *answer)
{
    if(totalPlayer == N/2)
    {
        vector<int> teamA;
        vector<int> teamB;
        printf("playerNumber = %d", playerNumber);

        for (int i = 1; i <= N; i++)
            check[i] ? teamA.push_back(i) : teamB.push_back(i);

        printf("teamA.size = %d\n", teamA.size());
        printf("teamB.size = %d\n", teamB.size());
        for (int i = 0; i < teamA.size(); i++)
            printf("%d ", teamA[i]);

        printf("\nteamB\n");
        for (int i = 0; i < teamB.size(); i++)
            printf("%d ", teamB[i]);
        int ability = getAbility(teamA, teamB);
        printf("\nability = %d\n", ability);
        if(*answer > ability || *answer == -1)
            *answer = ability;

        return;
    }

    for (int i = playerNumber; i < N; i++)
    {
        check[playerNumber] = true;
        DFS(i+1, totalPlayer + 1, N, answer);
        check[playerNumber] = false;
    }
}

int solution(int N)
{
    int answer = -1;

    DFS(1, 0, N, &answer);

    return answer;
}

int main()
{
    memset(check, false, sizeof(check));
    int N;
    scanf("%d", &N);

    S.resize(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            scanf("%d", &S[i][j]);

    printf("%d", solution(N));
}