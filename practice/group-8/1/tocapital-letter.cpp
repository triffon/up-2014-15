/*
 * Описание:
 *
 * Тази програма въвежда буква от клавиатурата, превръща я в главна, и я
 * извежда на екрана.
 *
 */

#include <iostream>
using namespace std;

int main()
{
    // въвеждаме буквата
    char a;
    cout << "Enter letter: ";
    cin >> a;

    // определяме разликата в кодовата таблица между малки и главни букви
    char z = 'z', Z = 'Z', diff = z - Z;
    
    //
    // изваждаме разликата от малката буква, за да получим главната, и
    // извеждаме главната буква
    //
    char b = a - diff;
    cout << "Capital letter: " << b;

    return 0;
}
