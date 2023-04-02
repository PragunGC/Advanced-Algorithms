#include <stdio.h>
#include <stdlib.h>

void bestfit(int n, float items[])
{
    float bins[n][n + 1];
    int numItems[n];
    int numBins = 0;
    for (int i = 0; i < n; i++)
    {
        numItems[i] = 0;
        for (int j = 0; j < n + 1; j++)
        {
            bins[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        float minVal = 2;
        int minIndex = -1;
        for (int j = 0; j < numBins; j++)
        {
            if (bins[j][n] + items[i] <= 1)
            {
                float mVal = 1 - bins[j][n] - items[i];

                if (mVal < minVal)
                {
                    minVal = mVal;
                    minIndex = j;
                }
            }
        }
        if (minIndex == -1)
        {
            numBins++;
            minIndex = numBins - 1;
        }
        bins[minIndex][n] += items[i];
        bins[minIndex][numItems[minIndex]] += items[i];
        numItems[minIndex]++;
    }
    printf("%d\n", numBins);
    for (int i = 0; i < numBins; i++)
    {
        for (int j = 0; j < numItems[i]; j++)
        {
            printf(".%d ", ((int)(bins[i][j]*10)) % 10);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    float items[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &items[i]);
    }
    bestfit(n, items);

    return 0;
}
