#include <iostream>
#include <string>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistance(string str1, string str2, int m, int n)
{
    if(m == 0) return n;

    if(n == 0) return m;


    if(str1[m - 1] == str2[n - 1])
        return editDistance(str1, str2, m - 1, n - 1);

    return 1 + min(editDistance(str1, str2, m, n - 1),
                   editDistance(str1, str2, m - 1, n),
                   editDistance(str1, str2, m -1, n - 1));
}

int main()
{
    string str1 = "sunday";
    string str2 = "Saturday";

    cout << editDistance(str1, str2, str1.size(), str2.size());

}