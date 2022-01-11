#include <stdio.h>

int moveSmallestDisk (int rod[], int smallestDir, int *ptrFrom, int *ptrTo)
{
    *ptrFrom = rod[1];
    *ptrTo = *ptrFrom + smallestDir;
    if ( *ptrTo > 3 )
        *ptrTo = 1;
    if ( *ptrTo < 1 )
        *ptrTo = 3;
    return 1;
}

int moveAlternateDisk (int rod[], int numberOfDisks, int *ptrFrom, int *ptrTo)
{
    // determine which disk is at the top of each rod
    int topDisk[4];
    int i;
    for ( i = 1; i <= 3; ++i )
        topDisk[i] = numberOfDisks + 1;
    for ( i = numberOfDisks; i >= 1; --i )
        topDisk[rod[i]] = i;

    switch (rod[1])
    {
        case 1:
            *ptrFrom = 2;
            *ptrTo = 3;
            break;
        case 2:
            *ptrFrom = 1;
            *ptrTo = 3;
            break;
        case 3:
            *ptrFrom = 1;
            *ptrTo = 2;
            break;
        default:
            printf ("error");
            break;
    }
    if ( topDisk[*ptrFrom] > topDisk[*ptrTo] ) {
        int temp;
        temp = *ptrFrom;
        *ptrFrom = *ptrTo;
        *ptrTo = temp;
    }

    return topDisk[*ptrFrom];
}

int destinationCount (int rod[], int numberOfDisks)
{
    int count = 0;
    int i;

    for ( i = 1; i <= numberOfDisks; ++i ) {
        if ( rod[i] == 3 )
            ++count;
    }

    return count;
}

int main (void)
{
    printf ("\nTower of Hanoi puzzle\n\n");
    printf ("number of disks? ");
    int numberOfDisks;
    scanf ("%i", &numberOfDisks);

    int smallestDir;
    if ( (numberOfDisks % 2) == 0 )
        smallestDir = 1;
    else
        smallestDir = -1;
    int rod[numberOfDisks + 1];
    // all disks start on the first rod
    int i;
    for ( i = 1; i <= numberOfDisks; ++i )
        rod[i] = 1;

    printf ("\nsolution\n\n");
    int moveCount = 0, disk, rodFrom, rodTo;

    do {
        ++moveCount;

        if ( (moveCount % 2) == 1 )
            disk = moveSmallestDisk (rod, smallestDir, &rodFrom, &rodTo);
        else
            disk = moveAlternateDisk (rod, numberOfDisks, &rodFrom, &rodTo);

        printf ("%i: disk %i rod %c to rod %c\n", moveCount, disk,
               rodFrom + 64, rodTo + 64);

        rod[disk] = rodTo;
    }
    while ( destinationCount (rod, numberOfDisks) != numberOfDisks );

    return 0;
}
