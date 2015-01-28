/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  Solution to the second problem of the `evens' section.
 *
 *        Version:  1.0
 *        Created:  28.01.2015  5,36,07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Radoslav Georgiev (sid), rgeorgiev583@gmail.com
 *        Company:  Faculty of Mathematics and Informatics at Sofia University
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;

void write_primes(int n)
{
    int a[MAX_SIZE];

    for (int i = 2; i <= n; i++)
        a[i - 2] = i;

    int i = 2;

    while (i * i <= n)
    {
        for (int j = i * i; j <= n; j += i)
            a[j - 2] = 1;

        i++;

        while (a[i - 2] == 1)
            i++;
    }

    for (int i = 0; i <= n - 2; i++)
        if (a[i] > 1)
            cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    write_primes(n);

    return 0;
}
