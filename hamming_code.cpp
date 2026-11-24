
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string data;
    cout << "Enter data: ";
    cin >> data;

    int m = data.length();
    int r = 0;

    // Calculate number of parity bits
    while (pow(2, r) < m + r + 1)
    {
        r++;
    }

    cout << "Number of parity bits: " << r << endl;

    int n = m + r;
    vector<int> h(n + 1, 0);

    int j = m - 1;
    int p = 1;

    // Place data and parity bits
    for (int i = 1; i <= n; i++)
    {
        if (i == p)
        {
            p = p * 2;
        }
        else
        {
            h[i] = data[j] - '0';
            j--;
        }
    }

    // Calculate parity bit values
    for (int p = 1; p <= n; p = p * 2)
    {
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if ((i / p) % 2 == 1)
            {
                count = count + h[i];
            }
        }

        h[p] = count % 2;

        cout << "r" << p << " = " << h[p] << endl;
    }

    // Print Hamming code
    cout << "Hamming Code: ";

    for (int i = n; i >= 1; i--)
    {
        cout << h[i];
    }

    return 0;
}
