#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void get(int a[], int n)
{
    /* To input 'n' values into an array */

    cout << "Enter the elements of the array separated by spaces or newline: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void maximumSumSubarray(int a[], int n)
{
    /* To to find subarray of maximum sum from an array */

    int maximum_sum = a[0], cs = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= 0)
        {
            cs = (cs >= 0) ? cs + a[i] : a[i];
            maximum_sum = max(cs, maximum_sum);
        }
        else
        {
            if (a[i] > cs)
            {
                cs = a[i];
                maximum_sum = max(cs, maximum_sum);
            }
            else
            {
                cs += a[i];
                cs = max(cs, 0);
            }
        }
    }

    cout << "Maximum Sum: " << maximum_sum << endl;
}

int main()
{
    /* Code Execution Starts here */

    // An initialisation using this format initialises the number of elements as present in {} and rest by 0
    int arr[100] = {0};
    int n;

    cout << "Enter number of elements in the array: ";
    cin >> n;

    get(arr, n);
    maximumSumSubarray(arr, n);

    return 0;
}