#include <iostream>
#include <cstring>
using namespace std;

const size_t MAX_SIZE = 1000;

int main()
{
    char message[MAX_SIZE];
    cin.getline(message, MAX_SIZE);
    int n = strlen(message);

    for (int i = 0; i < n; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
            message[i] = 'A' + (message[i] - 'A' + 13) % 26;
        else if (message[i] >= 'a' && message[i] <= 'z')
            message[i] = 'a' + (message[i] - 'a' + 13) % 26;
    }

    cout << message << endl;
}
