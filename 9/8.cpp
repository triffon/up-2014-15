#include <iostream>

void copy(bool a[8][8], bool b[8][8])
{
    for (size_t i = 0; i < 8; i++)
        for (size_t j = 0; j < 8; j++)
            a[i][j] = b[i][j];
}

void write

void write_rpos_rooks(bool b[8][8], size_t n, size_t x, size_t y)
{
    bool a[8][8];
    copy(a, b);

    for (size_t i = 0; i < 8; i++)
        for (size_t j = 0; j < 8; j++)
            if (a[x][i] || a[i][y])
            for (size_t i = 0; i < n; i++)
            for (s

int main()
{
    size_t a[8][8];

    
}
