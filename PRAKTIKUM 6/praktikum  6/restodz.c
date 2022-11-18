#include "queue.h"
#include <stdio.h>

int main()
{
    Queue kerjaan;
    kerjaan.idxHead = -1;
    kerjaan.idxTail = -1;

    int count = 0, maxima = 0, minima = 0;
    int command, tCook;

    scanf("%d", &command);
    while (command != 0)
    {
        if (command == 1)
        {
            scanf("%d", &tCook);
            if (tCook > 0 && kerjaan.idxTail < CAPACITY)
            {
                if (kerjaan.idxHead == -1)
                {
                    kerjaan.idxHead += 1;
                }
                kerjaan.idxTail += 1;
                kerjaan.buffer[kerjaan.idxTail] = tCook;
            }
        }
        else if (command == 2 && kerjaan.idxHead <= kerjaan.idxTail && kerjaan.idxHead != -1 && kerjaan.idxTail != -1)
        {
            int val = kerjaan.buffer[kerjaan.idxHead];

            if (kerjaan.idxHead == 0)
            {
                maxima = val;
                minima = val;
            }

            else
            {
                if (val > maxima)
                {
                    maxima = val;
                }
                if (val < minima)
                {
                    minima = val;
                }
            }
            kerjaan.idxHead++;
            count++;
        }
        scanf("%d", &command);
    }

    printf("%d\n%d\n%d\n", count, minima, maxima);
    return 0;
}