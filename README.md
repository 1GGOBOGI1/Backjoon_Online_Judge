# 알고리즘 문제풀이

## Backjoon Online Judge

### 푼 문제

|#|Title|Solution|Basic idea (One line)|
|:---|:---|:---|:---|
|1|[11724 연결 요소의 개수](https://www.acmicpc.net/group/board/view/7680/16582)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/11724.cpp)|아직 방문하지 않은 정점에 대하여 BFS 탐색 O(V+E)|
|2|[1707 이분 그래프](https://www.acmicpc.net/group/board/view/7680/16583)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1707.cpp)|1. BFS 탐색 O(V+E)<br>2. 2개의 색을 칠하며 편가르기|
|3|[1991번 : 트리 순회](https://www.acmicpc.net/problem/1991)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1991.cpp)|1. preOrder, inOrder, postOrder 기본<br>2. 출력 시 `static_cast<type>` 사용|
|4|[11725번 : 트리의 부모 찾기](https://www.acmicpc.net/problem/11725)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/11725.cpp)|BFS 탐색|
|5|[1167번 : 트리의 지름](https://www.acmicpc.net/problem/1167)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1167.cpp)|트리 지름 구하는 방법 - BFS 2번 돌리기|
|6|[11437번 : LCA](https://www.acmicpc.net/problem/11437)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/11437.cpp)|1. BFS를 이용하여 depth, parent 구해놓기<br>2. LCA|
|7|[1761번 : 정점들의 거리](https://www.acmicpc.net/problem/1761)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1761.cpp)|LCA 구하기|
|8|[11438번 : LCA 2](https://www.acmicpc.net/problem/11438)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/11438.cpp)|LCA binary lifting|
|9|[1967번 : 트리의 지름](https://www.acmicpc.net/problem/1967)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1967.cpp)|트리 지름 구하기 - BFS 2번|
|10|[2250번 : 트리의 높이와 너비](https://www.acmicpc.net/problem/2250)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/2250.cpp)|루트는 부모가 없다|
|11|[1068번 : 트리](https://www.acmicpc.net/problem/1068)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1068.cpp)|트리의 특정 노드 삭제|
|12|[5639번 : 이진 검색 트리](https://www.acmicpc.net/problem/5639)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/5639.cpp)|BST addNode, postOrder 구현|
|13|[3176번 : 도로 네트워크](https://www.acmicpc.net/problem/3176)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/3176.cpp)|LCA Binary Lifting 하면서 min max distance 구하기|
|14|[9237번 : 이장님 초대](https://www.acmicpc.net/problem/9237)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/9237.cpp)|덧셈 문제|
|15|[1927번 : 최소 힙](https://www.acmicpc.net/problem/1927)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1927.cpp)|1. 최소 힙 구현<br>2. `^`는 비트 연산자임. 제곱승은 `pow`로 계산|
|16|[11279번 : 최대 힙](https://www.acmicpc.net/problem/11279)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/11279.cpp)|최대 힙 구현|
|17|[11286번 : 절댓값 힙](https://www.acmicpc.net/problem/11286)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/11286.cpp)|최소 힙 응용|
|18|[1655번 : 가운데를 말해요](https://www.acmicpc.net/problem/1655)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1655.cpp)|최대 힙, 최소 힙 사용|
|19|[1715번 : 카드 정렬하기](https://www.acmicpc.net/problem/1715)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1715.cpp)|최소 힙|
|20|[1202번 : 보석 도둑](https://www.acmicpc.net/problem/1202))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1202.cpp)|최대 힙|
|21|[1826번 : 연료 채우기](https://www.acmicpc.net/problem/1826))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1826.cpp)|최대 힙|
|23|[2220번 : 힙 정렬](https://www.acmicpc.net/problem/2220))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/2220.cpp)|최대 힙 구현 관련 응용|
|24|[12767번 : Ceiling Function](https://www.acmicpc.net/problem/12767))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/12767.cpp)|1.BST<br>2.preOrder<br>3.STL `<set>`|
|25|[7785번 : 회사에 있는 사람](https://www.acmicpc.net/problem/7785))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/7785.cpp)|STL `<set>`을 이용하면 편리하게 BST를 사용할 수 있음|
|26|[1138번 : 한 줄로 서기](https://www.acmicpc.net/problem/1138))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1138.cpp)|그리디 알고리즘|
|27|[1871번 : 좋은 자동차 번호판](https://www.acmicpc.net/problem/1871))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1871.cpp)|문자열 다루기|
|28|[1935번 : 후위 표기식2](https://www.acmicpc.net/problem/1935))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1935.cpp)|스택 이용|
|29|[1937번 : 욕심쟁이 판다](https://www.acmicpc.net/problem/1937))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/1937.cpp)|단순 DP|
|30|[2440번 : 별 찍기 - 3](https://www.acmicpc.net/problem/2440))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/2440.cpp)|단순 for loop|
|31|[2660번 : 회장 뽑기](https://www.acmicpc.net/problem/2660))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/2660.cpp)|BFS 이용해서 노드의 깊이 재기|
|32|[11812번 : K진 트리](https://www.acmicpc.net/problem/11812))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/11812.cpp)|K진 트리 공식 이용|
|33|[13251번 : 조약돌 꺼내기](https://www.acmicpc.net/problem/13251))|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/13251.cpp)|소수점 계산 주의|


### 시도했으나 아직 풀지 못한 문제


|When|Title|Solution|
|:---|:---|:---|
|`2020-04-09`|[2213번 : 트리의 독립집합](https://www.acmicpc.net/problem/2213)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/2213.cpp)|
|`2020-04-24`|[3116번 : 생물학자](https://www.acmicpc.net/problem/3116)|[C++](https://github.com/kjh107704/Algorithm/blob/master/BOJ/3116.cpp)|