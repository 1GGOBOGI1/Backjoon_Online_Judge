#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;

    map<string, int> dic;

    // 사전 초기화 (길이가 1인 모든 단어 포함, A:1, ..., Z:26)
    for(int i = 0; i < 26; i++)
    {
        string tmp = "";
        tmp += ('A' + i);
        dic.insert(make_pair(tmp,i+1));
    }

    map<string, int>::iterator map_iter(dic.begin());

    // 탐색 시작 위치를 나타내는 변수
    int index = 0;

    while(index < msg.length())
    {
        int maxLengthIndex = 0;

        // len = index에서 시작한 substring의 길이
        for(int len = 1; index + len -1 < msg.length(); len++)
        {
            // msg의 index에서 시작하여 길이가 len 만큼의 문자열이 사전에 있는지 탐색
            map_iter = dic.find(msg.substr(index,len));

            // 사전에 없다면
            if(map_iter == dic.end())
            {
                // maxLengthIndex에는 index에서 시작하여 길이가 len-1인 문자열의 사전 색인 번호가 저장되어 있음
                answer.push_back(maxLengthIndex);
                // 새로운 문자열을 insert
                dic.insert(make_pair(msg.substr(index,len),dic.size()+1));
                index += len - 1;
                break;
            }
            // 사전에 있다면, maxLengthIndex에 사전 색인 번호 저장
            maxLengthIndex = map_iter -> second;

            // 문자열의 끝에 도달한 경우
            if(index + len == msg.length())
            {
                // 지금까지 찾았던 maxLengthIndex를 정답에 넣음
                answer.push_back(maxLengthIndex);
                index += len;
                break;
            }
                
        }
    }

    return answer;
}

int main()
{
    string msg;
    cin>>msg;

    vector<int> answer = solution(msg);

    for(int i = 0; i < answer.size(); i++)
        printf("%d ", answer[i]);
}