
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

    // Step 1: Calculate number of parity bits
    while (pow(2, r) < m + r + 1)
    {
        r++;
    }

    cout << "Number of parity bits: " << r << endl;

    int n = m + r;
    vector<int> h(n + 1, 0);

    int j = m - 1;
    int p = 1;

    // Step 2: Place data and parity bits
    for (int i = 1; i <= n; i++)
    {
        if (i == p)
        {
            h[i] = 0;
            p = p * 2;
        }
        else
        {
            h[i] = data[j] - '0';
            j--;
        }
    }

    // Step 3: Calculate parity bit values
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

        if (count % 2 == 0)
        {
            h[p] = 0;
        }
        else
        {
            h[p] = 1;
        }

        cout << "r" << p << " = " << h[p] << endl;
    }

    // Step 4: Print Hamming code
    cout << "Hamming Code: ";

    for (int i = n; i >= 1; i--)
    {
        cout << h[i];
    }

    cout << endl;

    return 0;
}
