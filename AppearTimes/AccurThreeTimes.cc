#include <iostream>
#include <vector>

using namespace std;

int getOnlyOne(vector<int>& array)
{
    int length = array.size();

    int res = 0;

    for(int i = 0; i < 32; i++)
    {
        int count = 0;
        int mask = 1 << i;

        for(int j = 0; j < length; j++)
        {
            if(array[j] & mask)
                count++;
        }

        if(count % 3)
            res = res | mask;
    }

    return res;
}