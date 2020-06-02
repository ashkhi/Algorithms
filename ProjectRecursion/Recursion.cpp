#include <iostream>

using namespace std;

void solveTowerOfHanoi(int numOfDiscs, char fromTower, char toTower, char helpTower)
{
    if(numOfDiscs == 1)
    {
        cout << "Move disc " << numOfDiscs << " from tower " << fromTower << " to tower " << toTower << endl;
        return;
    }
    else
    {
        solveTowerOfHanoi(numOfDiscs-1, fromTower, helpTower, toTower);
        cout << "move disc " << numOfDiscs << " from tower " << fromTower << " to tower " << toTower << endl;
        solveTowerOfHanoi(numOfDiscs-1, helpTower, toTower, fromTower);
    }
}

int main()
{
    int numOfDiscs;
    cout << "Enter number of discs for tower of Hanoi problem : ";
    cin >> numOfDiscs;

    solveTowerOfHanoi(numOfDiscs, 'A', 'B', 'C');

    return 0;
}