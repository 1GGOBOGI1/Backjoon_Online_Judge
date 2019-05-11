void ShellSort(int a[],int n)
{
    int i, j, gap, temp;
    for (gap = n / 2; gap > 0;gap /=2)
    {
        /*
            gap을 홀수로 다루는 것이
            성능에 더 좋은 영향을 끼친다는
            연구 결과를 토대로 gap이 짝수이면
            1을 더해서 홀수로 만들어줌
        */
        if(gap%2==0)
            gap++; 
        for (i = gap; i < n;i++)
        {
            temp = a[i];
            for (j = i; j >= gap;j-=gap)
            {
                if(temp<a[j-gap])
                    a[j] = a[j - gap];
                else
                    break;
            }
            a[j] = temp;
        }
    }
}
