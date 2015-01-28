/*
 * =====================================================================================
 *
 *       Filename:  3.cpp
 *
 *    Description:  Solution to the third problem of the `evens' section.
 *
 *        Version:  1.0
 *        Created:  28.01.2015  6,00,07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Radoslav Georgiev (sid), rgeorgiev583@gmail.com
 *        Company:  Faculty of Mathematics and Informatics at Sofia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 1000;
const char diff = 'a' - 'A';

bool isWordChar(char c)
{
    return c == '(' || c == ')' || c == '-' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

const char* skipWhitespaceReverse(const char* s)
{
    while (*s == ' ')
        s--;

    return s;
}

const char* goToEnd(const char* s)
{    
    while (*s)
        s++;

    return s;
}

char toUpper(char c)
{
    return c >= 'a' && c <= 'z' ? c - diff : c;
}

char toLower(char c)
{
    return c >= 'A' && c <= 'Z' ? c + diff : c;
}

void swap(char* a, char* b)
{
    char x = *a;
    *a = *b;
    *b = x;
}

// Ако изречението е невалидно, връщаме NULL
char* reverseSentence(char* rev, const char* s)
{
    if (!s)
        return NULL;

    const char* end = goToEnd(s);
    end--;

    if (end < s || *end != '!' && *end != '.' && *end != '?')
        return NULL;

    end--;

    do
    {
        const char* beg = end;
    
        while (beg >= s && isWordChar(*beg))
            beg--;

        if (beg == end)
            return NULL;

        if (beg++ < s)
        {
            char first[2];
            strncat(first, beg, 1);
            *first = toLower(*first);
            strcat(rev, first);
            strncat(rev, beg + 1, end - beg);
            end = beg - 1;
        }
        else
        {
            strncat(rev, beg, end - beg + 1);
            end = beg - 1;

            if (*end != ' ')
                return NULL;

            end--;

            if (end < s)
                return NULL;

            if (*end == ',' || *end == ':' || *end == ';')
                strncat(rev, end, 1);

            strncat(rev, end + 1, 1);
        }
    }
    while (end >= s);

    *rev = toUpper(*rev);
    char *p = rev, *lp = NULL;
    int b = 0;

    while (p)
    {
        if (*p == '(')
        {
            b++;

            if (lp && b == 0)
            {
                swap(p, lp);
                lp = NULL;
            }
        }
        else if (*p == ')')
        {
            b--;

            if (b == -1)
                lp = p;
        }

        p++;
    }

    return rev;
}

int main()
{
    char s[MAX_SIZE], rev[MAX_SIZE];
    cin.getline(s, MAX_SIZE);

    cout << reverseSentence(rev, s) << endl;

    return 0;
}
