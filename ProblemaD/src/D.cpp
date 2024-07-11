#include <bits/stdc++.h>

using namespace std;

int counters[256];

int main(int argc, char * argv[])
{
    string word;

    int T;
    cin >> T;

    while (--T >= 0 && cin >> word)
    {
        for (int i = 0; i < 256; i++)
            counters[i] = 0;

        for (size_t i = 0; i < word.size(); i++)
        {
            counters[(int)word[i]]++;
        }
        bool all_equal = true;
        int c = -1;
        for (int i = 0; i < 256 && all_equal; i++)
        {
            if (counters[i] > 0)
            {
                if (c == -1)
                {
                    c = counters[i];
                }
                else
                {
                    if (c != counters[i])
                    {
                        all_equal = false;
                    }
                }
            }
        }
        cout << (all_equal ? "SI" : "NO") << endl;
    }

    return EXIT_SUCCESS;
}
