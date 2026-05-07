#include <iostream>

using namespace std;

int main()
{
    int N;

    while (cin >> N && N != -1)
    {
        if (N < 13 || N >= 100)
        {
            continue;
        }

        bool found = false;

        for (int m = 0; m < 10000; ++m)
        {
            int survivor = 0;
            for (int i = 2; i <= N-1; ++i)
            {
                survivor = (survivor + m) % i;
            }

            if (survivor + 2 == 13)
            {
                cout << m << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "No solution." << endl;
        }
    }
    return 0;
}