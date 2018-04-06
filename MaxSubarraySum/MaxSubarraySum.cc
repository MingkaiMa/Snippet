#include <iostream>

using namespace std;

//if all is minus, return the maximum
int MaxSum1(int* A, int n)
{
    int max_now = A[0];
    int max_so_far = A[0];
    for(int i = 1; i < n; i++)
    {
        max_now = max(A[i], max_now + A[i]);
        max_so_far = max(max_so_far, max_now);
    }
    return max_so_far;
}

//if all is minus, return 0
int MaxSum2(int* A, int n)
{
    int max_now = 0;
    int max_so_far = 0;
    for(int i = 0; i < n; i++)
    {
        max_now = max(0, max_now + A[i]);
        max_so_far = max(max_now, max_so_far);
    }

    return max_so_far;
}

// return start index
void MaxSum3(int* A, int n)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int startIndex = 0;
    int maxIndex = 0;

    for(int i = 0; i < n; i++)
    {
        if(sum + A[i] < A[i])
        {
            cout << "iii: " << i << endl;
            sum = A[i];
            startIndex = i;
        }
        else
            sum += A[i];


        if(sum > maxSum)
        {
            maxSum = sum;
            maxIndex = startIndex;
        }
    }

    int maxEndIndex = maxIndex;
    int sumK = 0;
    while(sumK != maxSum)
    {
        sumK += A[maxEndIndex];
        maxEndIndex++;
    }
    maxEndIndex -= 1;
    cout << "MaxSum is: " << maxSum << " start from " << maxIndex << " end in " << maxEndIndex << endl;
}

int main()
{
    //int A[] = {-2, 5, 3, -6, 4, -8, 6};
    int A[] = {-4,-1,-2,-3};
    //cout << MaxSum2(A, 7) << "\n";
    MaxSum3(A, 4);
}