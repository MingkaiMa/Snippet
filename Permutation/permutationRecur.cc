#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void permutateCore(vector<char>& arr, int start, vector<vector<char>>& res)
{
    if(start == arr.size())
    {
        res.push_back(arr);
        return;
    }


    for(int i = start; i < arr.size(); i++)
    {
        swap(arr[start], arr[i]);
        permutateCore(arr, start + 1, res);
        swap(arr[start], arr[i]);
    }
}

//no duplicate

bool toSwap(vector<char>& arr, int i, int j)
{
    for(int k = i; k < j; k++)
    {
        if(arr[k] == arr[j])
            return false;
    }
    return true;
}
void permutateCoreNoduplicate(vector<char>& arr, int start, vector<vector<char>>& res)
{
    if(start == arr.size())
    {
        res.push_back(arr);
        return;
    }


    for(int i = start; i < arr.size(); i++)
    {
        if(!toSwap(arr, start, i))
            continue;

        swap(arr[start], arr[i]);
        permutateCoreNoduplicate(arr, start + 1, res);
        swap(arr[start], arr[i]);
    }
}

vector<vector<char>> permutate(vector<char>& arr)
{
    int start = 0;
    vector<vector<char>> res;
    permutateCoreNoduplicate(arr, start, res);
    return res;
}

int main()
{
    vector<char> arr = {'a', 'b', 'b'};
    vector<vector<char>> res = permutate(arr);
    for(auto& vc: res)
    {
        for(auto& c: vc)
            cout << c << ", ";
        cout << "\n";
    }
}