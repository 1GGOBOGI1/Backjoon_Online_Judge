#include <iostream>
#include <cstring>
using namespace std;

int invest[302][21];
int investGap[302][21];
int maxComp[302][2];
// maxComp[투자금액][0] = 현 투자금액에서 받을 수 있는 최고이득
// maxComp[투자금액][1] = 돈 몰빵한 기업번호
int ans[302];
// ans[투자금액] = 현 투자금액에서 최고 이득
int D[302][21];
// D[투자금액][회사번호] = 현 투자금액에서 각 회사번호에 얼마를 투자하였는가?
int N, M;

int solve(int pay)
{
    //cout << "현재 " << pay << "만원 투자중\n";
    ans[pay] = maxComp[pay][0];
    D[pay][maxComp[pay][1]] = pay;
    //cout << "몰빵할 경우 이득: " << ans[pay] << "\n";

    int max = -1, max_pay = -1, max_company = -1;

    //1만원을 어디에 더 투자할 것인가? i회사에 1만원을 더 투자하는 경우
    for (int i = 1; i < pay;i++)
    {
        if(D[pay-1][i]+1 <= N)
        {
            if (max < ans[pay - 1] + investGap[D[pay - 1][i] + 1][i])
            {
                max = ans[pay - 1] + investGap[D[pay - 1][i] + 1][i];
                max_company = i;
            }
        }    
    }
    //cout << "1만원 더 투자할 경우 이득: " << max << "\n";

    if(ans[pay] < max) // 몰빵보다 1만원 더 투자가 이득인 경우
    {
        ans[pay] = max;
        D[pay][maxComp[pay][1]] = 0;

        for (int i = 1; i < M + 1;i++)
        {
            D[pay][i] = D[pay - 1][i];
        }

        D[pay][max_company]++;
    }

    if(pay == N)
        return ans[pay];
    else
    {
        return solve(pay + 1);
    }
}

int main()
{
    int input,max = -1,max_index = -1;
    cin >> N >> M;

    memset(ans, 0, sizeof(ans));
    memset(D, 0, sizeof(D));

    for (int i = 1; i < N + 1; i++)
    {
        cin >> input;
        for (int j = 1; j < M+1; j++)
        {
            cin >> invest[i][j];
            // 1만원을 j회사에 더 투자하면 investGap[i][j]만큼의 이익이 생김
            investGap[i][j] = invest[i][j] - invest[i - 1][j];
            if (max < invest[i][j])
            {
                max = invest[i][j];
                max_index = j;
            }
        }
        maxComp[i][0] = max;
        maxComp[i][1] = max_index;
    }

    cout << solve(1) <<"\n";

    for (int i = 1; i < M + 1;i++)
    {
        cout << D[N][i] << " ";
    }
}