#include <stdio.h>
int countDigit(int k);

int main(void)
{
      int n, k, i, sum, p = 1;
      const int unhappy[8] = {4, 16, 37, 58, 89, 145, 42, 20};
      scanf("%d", &sum);

      do
      {
            k = countDigit(sum); //k=숫자의 자릿수
            n = sum;

            for (sum = 0, i = 0; i < k; i++)
            {
                  sum += (n % 10) * (n % 10);
                  n = n / 10;
            }
            if (sum == 1)
            {
                  printf("HAPPY\n");
                  p = 0;
                  break;
            }

            for (i = 0; i < 8; i++)
            {
                  if (sum == unhappy[i])
                  {
                        printf("UNHAPPY\n");
                        p = 0;
                        break;
                  }
            }
      } while (p);

      return 0;
}

int countDigit(int n)
{
      int i;
      for (i = 1; n > 9; i++)
      {
            n /= 10;
      }
      return i;
}