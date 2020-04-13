#include <bits/stdc++.h>
using namespace std;

// Only one method possible
int Kadane(int arr[], int n)
{
    int Max_so_far = 0;
    int Max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        Max_ending_here += arr[i];
        if (Max_ending_here > Max_so_far)
        {
            Max_so_far = Max_ending_here;
        }
        if (Max_ending_here < 0)
        {
            Max_ending_here = 0;
        }
    }

    return Max_so_far;
}

int maxCircularSum(int *arr, int n)
{
    int maxKadane = Kadane(arr, n);
    int totalsum = 0;

    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }

    int maxKadaneInverted = Kadane(arr, n);

    int maxWrappedSum = totalsum + maxKadaneInverted; // Wrappedsum = Total - ( - (maxKadaneInverted));

    return max(maxKadane, maxWrappedSum);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << maxCircularSum(arr, n) << endl;
    }
}