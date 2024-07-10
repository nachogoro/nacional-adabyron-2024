#include <bits/stdc++.h>

using namespace std;

typedef long long my_long;

typedef std::pair<my_long, my_long> my_tuple;

my_tuple    wizards[300000];
my_long     accumulates[300000];

int main(int argc, char * argv[])
{
    int T, N;
    cin >> T;

    while (--T >= 0)
    {
        cin >> N;

        for (int n = 0; n < N; n++)
        {
            cin >> wizards[n].first;
            wizards[n].second = n + 1;
        }

        sort(wizards, wizards + N);

        accumulates[0] = wizards[0].first;
        for (int n = 1; n < N; n++)
            accumulates[n] = accumulates[n - 1] + wizards[n].first;

        int n;
        for (n = N - 2; n >= 0; n--)
        {
            if (accumulates[n] < wizards[n + 1].first) break;
        }
        if (n < 0)
            n = N - 1;
        else
            n++;

        cout << wizards[n].second << endl;
    }

    return EXIT_SUCCESS;
}
