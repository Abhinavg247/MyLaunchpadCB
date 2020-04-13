#include <bits/stdc++.h>
using namespace std;

void maxsubarraysum1(int arr[], int n)
{
    int count = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++, ++count)
    {
        for (int j = i; j < n; j++, ++count)
        {
            int curr_sum = 0;
            for (int k = i; k <= j; k++, ++count)
            {
                // cout << "SubArray element : " << arr[k] << " & count: " << count << " ";
                cout << arr[k] << " ";
                curr_sum += arr[k];
            }
            // cout << " & count: " << count;
            max_sum = max(max_sum, curr_sum);
            cout << endl;
        }
    }

    cout << "O(N^3) max_sum is : " << max_sum << endl;

    // cout << "Final count : " << count << endl;
}

void maxsubarraysum2(int arr[], int n)
{
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            max_sum = max(max_sum, curr_sum);
        }
    }

    cout << "O(N^2) max_sum is : " << max_sum << endl;
}

int maxSubArraySum3(int arr[], int n) // KADANE'S ALGORITHM
{
    int sidx = 0, eidx = 0, maxsum = arr[0];
    for (int i = 1; i < n; i++)
    {
        int prev_sum = maxsum;
        maxsum = max(arr[i], max(prev_sum + arr[i], prev_sum));
        if (maxsum == arr[i])
        {
            sidx = i;
            eidx = i;
        }
        else if (maxsum == prev_sum + arr[i])
        {
            eidx = i;
        }
    }

    cout << " Array with max sum is : " << endl;

    for (int i = sidx; i <= eidx; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "O(N) max_sum is : " << maxsum << endl;

    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {-4, 1, 3, -2, 6, 2, -8, -9, 4};
    maxsubarraysum1(arr, 9);
    maxsubarraysum2(arr, 8);
    maxSubArraySum3(arr, 8);
    return 0;
}
