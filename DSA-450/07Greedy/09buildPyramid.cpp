#include <bits/stdc++.h>
using namespace std;

int maxLevel(int boxes[], int n)
{
    sort(boxes, boxes + n);

    int prevWidth = boxes[0];
    int prevBox = 1;
    int levelCount = 1;

    int currWidth = 0;
    int currBox = 0;
    for (int i = 1; i < n; i++)
    {
        currWidth += boxes[i];
        currBox += 1;
        if (currWidth > prevWidth && currBox > prevBox)
        {
            prevWidth = currWidth;
            prevBox = currBox;

            currWidth = 0;
            currBox = 0;

            levelCount += 1;
        }
    }
    return levelCount;
}

int main()
{
    int boxes[] = {10, 20, 30, 50, 98, 78, 56, 6, 89, 87, 6};
    int n = sizeof(boxes) / sizeof(boxes[0]);
    cout << maxLevel(boxes, n) << endl;
    return 0;
}
