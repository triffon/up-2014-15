#include <iostream>

using namespace std;

int main()
{
    size_t n; cin >> n;
    double sum = 0;

    for (size_t i = 1; i <= n; i++)
    {
        size_t denom = 1;

        for (size_t j = 1; j <= i; j++)
        {
            denom *= i;
        }

        sum += 1.0 / denom;
    }

    cout << sum << endl;
    sum = 0;

    for (size_t i = 1; i <= n; i++)
    {
        size_t denom = 1;

        for (size_t j = 1; j <= n - i + 1; j++)
        {
            denom *= i;
        }

        sum += 1.0 / denom;
    }

    cout << sum << endl;
    return 0;
}
