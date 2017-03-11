#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int SumNumber (long long unsigned x)
{
    int sum = 0;
    while (x)
    {
        sum += (x % 10);
        x /= 10;
    }

    return sum;
}

long long unsigned FirstMax (long long unsigned x)
{
    long long unsigned first_max;
    int count = -1;

    while (x)
    {
        x /= 10;
        ++count;
    }
    first_max = ((long long unsigned)pow(10, count) - 1);

    return first_max;
}

int main()
{
    long long unsigned x;
    long long unsigned max;
    long long unsigned step;

    clock_t start_time=clock();

    cin >> x;
    max = FirstMax(x);
    step = (max + 1);

    if ((x >= 1) && (x <= 9))
    {
        cout << x << endl;
        return 0;
    }

    if (SumNumber(x) >= SumNumber(max))
    {
        cout << x << endl;
        return 0;
    }
    else
        while (x >= max)
            max += step;

    max -= step;
    cout << max << endl;
    clock_t end_time =clock();
    int time=(int)(end_time-start_time)/CLOCKS_PER_SEC;
    cout << time << endl;
    return 0;
}
