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

bool isInnerWordChar(char c)
{
    return c == '-' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

bool isBeginWordChar(char c)
{
    return isInnerWordChar(c) || c == '"' || c == '\'' || c == '(';
}
 
bool isEndWordChar(char c)
{
    return isInnerWordChar(c) || c == '"' || c == '\'' || c == ')';
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

const char* goToEnd(const char* s)
{ 
    while (*s)
        s++;

    return s;
}

char* appendBegin(char* rev, const char* beg, const char* end)
{
    if (isInnerWordChar(*end) && isBeginWordChar(*beg) && !isInnerWordChar(*beg))
        if (*beg != '(')
            strncat(rev, beg, 1);
        else
            strcat(rev, ")");

    return rev;
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

    const char* stop = end;
    end--;

    if (end < s)
        return NULL;

    do
    {
        const char *beg = end;

        if (!isEndWordChar(*beg))
            return NULL;

        beg--;

        while (beg >= s && isInnerWordChar(*beg))
            beg--;

        if (beg < s || !isBeginWordChar(*beg))
            beg++;

        if (isInnerWordChar(*beg) && !isInnerWordChar(*end))
            if (*end != ')')
                strncat(rev, end, 1);
            else
                strcat(rev, "(");

        if ((isInnerWordChar(*end) && !isInnerWordChar(*beg) ? beg++ : beg) == s)
        {
            char first[2];
            first[0] = *beg;
            first[1] = 0;
            first[0] = toLower(first[0]);
            strcat(rev, first);
            strncat(rev, beg + 1, (!isInnerWordChar(*end) ? end - 1 : end) - beg);
            appendBegin(rev, beg - 1, end);
        }
        else
        {
            strncat(rev, beg, (!isInnerWordChar(*end) ? end - 1 : end) - beg + 1);
            beg--;

            if (isInnerWordChar(*end) && isBeginWordChar(*beg) && !isInnerWordChar(*beg))
                beg--;

            if (*beg != ' ')
                return NULL;

            beg--;

            if (beg < s)
                return NULL;

            if (*beg == ',' || *beg == ':' || *beg == ';')
                strncat(rev, beg, 1);

            beg += 2;
            appendBegin(rev, beg, end);
            strncat(rev, beg - 1, 1);
        }

        end = beg - 2;
    }
    while (end >= s);

    strncat(rev, stop, 1);
    char* firstInnerWordPos = isBeginWordChar(*rev) && !isInnerWordChar(*rev) ? rev + 1 : rev;
    *firstInnerWordPos = toUpper(*firstInnerWordPos);

/*
    char *p = rev, *lp = NULL;
    int b = 0;

    while (*p)
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
*/

    return rev;
}

int main()
{
    char s[MAX_SIZE], rev[MAX_SIZE];
    cin.getline(s, MAX_SIZE);

    cout << reverseSentence(rev, s) << endl;

    return 0;
}
