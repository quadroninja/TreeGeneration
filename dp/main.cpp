#include <iostream>

using namespace std;

int abs(int x) {return x > 0 ? x : -x;}


int main()
{
    int a, b, d;
    cin >> a >> b >> d;
    if (abs(a + b) % 2 == 0)
        cout << (a + b) / 2;
    else
    {

    }

    return 0;
}
