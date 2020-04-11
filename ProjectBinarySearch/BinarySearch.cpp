#include <iostream>
#include <vector>

using namespace std;

class BinarySearch
{
    private:
        vector<int>* numbers;
        int numberToSearch;
    
    public:
        BinarySearch();
        ~BinarySearch();

        void setNumberToSearch(int);
        int getNumberToSearch();
        void setNumbersVector(vector<int>*);
        vector<int>* getNumbersVector();
        bool isNumbersInAscendingOrder();

        int binarySearch(int, int);
};

BinarySearch::~BinarySearch()
{
    cout << "\nObject destroyed \n";
}

BinarySearch::BinarySearch()
{
    numbers = new vector<int>(10);
    for (int i=0; i<10; ++i)
    {
        numbers->at(i) = 0;
    }

    numberToSearch = 0;

    cout << "\nObject created \n";
}

void BinarySearch::setNumberToSearch(int num)
{
    numberToSearch = num;
}

int BinarySearch::getNumberToSearch()
{
    return numberToSearch;
}

void BinarySearch::setNumbersVector(vector<int>* numVect)
{
    if (numVect && numbers)
    {
        for (int i=0; i<10; ++i)
        {
            numbers->at(i) = numVect->at(i); 
        }
    }
}

vector<int>* BinarySearch::getNumbersVector()
{
    return numbers;
}

bool BinarySearch::isNumbersInAscendingOrder()
{
    if (numbers)
    {
        for (int i=0; i<9; ++i)
        {
            if (numbers->at(i) > numbers->at(i+1))
            {
                return false;
            }
        }
        return true;
    }

    return false;
}

int BinarySearch::binarySearch(int start, int end)
{
    if (numbers && isNumbersInAscendingOrder())
    {
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if (getNumberToSearch() == numbers->at(mid))
            {
                return mid;
            }
            else if (getNumberToSearch() < numbers->at(mid))
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
    }

    return -1;
}

int main()
{
    int num;
    cout << "Please enter a number to search :";
    cin >> num;

    vector<int>* vect = new vector<int>(10);
    cout << "\nPlease enter 10 integers in asending order to populate the vector:";
    for (int i=0; i<10; ++i)
    {
        cin >> vect->at(i);
    }

    BinarySearch* bs1 = new BinarySearch();
    bs1->setNumberToSearch(num);
    bs1->setNumbersVector(vect);

    int pos = bs1->binarySearch(0, 9);
    if (pos >=0 &&  pos < 10)
    {
        cout << "\n" << bs1->getNumberToSearch() << " is present at location " <<  pos+1 << "." << endl;
    }
    else
    {
        cout << "\n" << bs1->getNumberToSearch() << " is not present in the vector or vector is not in ascending order." << endl;
    }

    delete(bs1);
    
    return 0;
}