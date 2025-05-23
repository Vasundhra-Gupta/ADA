#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char from, char to, char another)
{
    if (n > 0)
    {

        TowerOfHanoi(n - 1, from, another, to);
        cout << "move disk " << from << " to " << to << endl;
        TowerOfHanoi(n - 1, another, to, from);
    }
}

int main()
{
    TowerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}