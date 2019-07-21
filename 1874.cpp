#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

void print_lists(vector<int> _nums, stack<int> _tmps, int _point)
{
    cout << "remaining original vector" << endl;
    for (int i = _point; i < _nums.size(); i++)
        cout << _nums[i] << " ";
    cout << endl;
    cout << "remaining tmp stack" << endl;
    for (int i = 0; i < _tmps.size(); i++)
        cout << _nums[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> original_num; //1~n까지의 숫자를 오름차순으로 담고있는 벡터
    vector<int> target; //맞춰야할 수열
    stack<int> tmp; //수열을 만들 때 사용할 stack
    string ans = ""; //정답 출력

    for (int i = 1; i < n + 1; i++)
        original_num.push_back(i);

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        target.push_back(input);
    }

    bool check = true;
    int point = 0; //original_num 벡터의 탐색 시작지점을 지정하는 변수 

    //target 수열의 앞부분부터 맞춰 나감
    for (int i = 0; i < n && check == true; i++)
    {
        // cout << "i = " << i << "\n\n";
        // cout << "now lists" << endl;
        // print_lists(original_num, tmp, point);

        //tmp stack의 top에 타겟 숫자가 있다면 tmp에서 pop하면 됨
        if (!tmp.empty() && tmp.top() == target[i])
        {
            tmp.pop();
            ans += "-\n";
            // cout << "tmp pop" << endl;
            // print_lists(original_num, tmp, point);
        }
        //tmp stack의 top이 타겟 숫자가 아닐 때, 아직 tmp에 넣은 적이 없는 original_num 벡터에 타겟 숫자가 있는 경우
        // 타겟 숫자가 tmp stack의 top이 될 때 까지 tmp에 push하고 top이 되면 pop 하면 됨
        else if (!original_num.empty() && find(original_num.begin() + point, original_num.end(), target[i]) != original_num.end())
        {
            //tmp가 비었으면 일단 하나 넣고 시작
            if (tmp.empty())
            {
                tmp.push(original_num[point]);
                point++;
                ans += "+\n";
                // cout << "tmp push" << endl;
                // print_lists(original_num, tmp, point);
            }
            //tmp의 top이 타겟 숫자가 될 때 까지 original_num의 숫자를 순서대로 넣음
            while (tmp.top() != target[i])
            {
                tmp.push(original_num[point]);
                point++;
                ans += "+\n";
                // cout << "tmp push" << endl;
                // print_lists(original_num, tmp, point);
            }
            //tmp의 top에 타겟 숫자가 오면 pop함
            tmp.pop();
            ans += "-\n";
            // cout << "tmp pop" << endl;
            // print_lists(original_num, tmp, point);
        }
        // tmp stack의 top이 타겟 숫자가 아님 && original_num에도 타겟 숫자가 없을 경우
        // 이건 tmp stack에 이미 타겟 숫자가 들어가 있다는 것. top이 아닌 이상 그 타겟 숫자를 먼저 pop 할 수 없으므로 수열 못 만듦
        else
        {
            check = false;
            ans = "NO";
        }

        // cout << "\n\n";
    }

    cout << ans << endl;
}