#include <iostream>
using namespace std;

int calculateAmount(int *arr, int n)
{
    int *left = new int[n];
    int *right = new int[n];

    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }

        left[i] = max;
    }

    max = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }

        right[i] = max;
    }

    int amount = 0;

    for (int i = 0; i < n; i++)
    {
        amount += min(left[i], right[i]) - arr[i];
    }

    return amount;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n]; // height of buildings array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << calculateAmount(arr, n) << endl;
    return 0;
}
