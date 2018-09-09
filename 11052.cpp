#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int prime[200] = {0};
int ans[3] = {0};

void isPrime(){
      int i, j, cnt = 1;
      prime[0] = 2;
      for (i = 3; i < 1010; i++){
            for (j = 2; j < i; j++)if (i % j == 0)break;
            if (i == j)prime[cnt++] = i;
      }
}

int isitPrime(int num){
      int i;
      if (num == 1)return 0;
      else if (num == 2)return 1;
      else{
            for (i = 2; i <= sqrt((double)num); i++)if (num % i == 0)return 0;
            return 1;
      }
}

int find_prime(int num){
      int i = 0;
      for (;; i++)if (prime[i] >= num)break;
      return i;
}

int answer(int num){
      int prime_index = find_prime(num) - 1;
      if (prime_index == -1)return 0;
      while (1){
            int prime1 = prime[prime_index];
            if (isitPrime(num - prime1)){
                  ans[1] = prime1;
                  ans[2] = num - prime1;
                  return 1;
            }
            else{
                  if (prime_index == 0)return 0;
                  prime_index = prime_index - 1;
            }
      }
}

int main(){
      int T;
      cin >> T;
      while (T--){
            int num;
            cin >> num;
            isPrime();
            int prime_index = find_prime(num) - 1;
            while (1){
                  int prime1 = prime[prime_index];
                  if (answer(num - prime1)){
                        ans[0] = prime[prime_index];
                        break;
                  }
                  prime_index = prime_index - 1;

                  if (prime_index == -1){
                        cout << 0 << endl;
                        continue;
                  }
            }
            sort(ans, ans + 3);
            for (int i = 0; i < 3; i++)cout << ans[i] << " ";
            cout << "\n";
      }
}