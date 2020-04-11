#include <iostream>
#include <vector>

using namespace std;

class LinearSearch
{
    private:
        vector<int>* numbers;
        int numberToSearch;
    
    public:
        LinearSearch();
        ~LinearSearch();

        void setNumberToSearch(int);
        int getNumberToSearch();
        void setNumbersVector(vector<int>*);
        vector<int>* getNumbersVector();

        int linearSearch();
};

LinearSearch::~LinearSearch()
{
    cout << "\nObject destroyed \n";
}

LinearSearch::LinearSearch()
{
    numbers = new vector<int>(10);
    for (int i=0; i<10; ++i)
    {
        numbers->at(i) = 0;
    }

    numberToSearch = 0;

    cout << "\nObject created \n";
}

void LinearSearch::setNumberToSearch(int num)
{
    numberToSearch = num;
}

int LinearSearch::getNumberToSearch()
{
    return numberToSearch;
}

void LinearSearch::setNumbersVector(vector<int>* numVect)
{
    if (numVect && numbers)
    {
        for (int i=0; i<10; ++i)
        {
            numbers->at(i) = numVect->at(i); 
        }
    }
}

vector<int>* LinearSearch::getNumbersVector()
{
    return numbers;
}

int LinearSearch::linearSearch()
{
    if (numbers)
    {
        for (int i=0; i<10; ++i)
        {
            if(numbers->at(i) == numberToSearch)
            {
                return i;
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
    cout << "\nPlease enter 10 integers to populate the vector:";
    for (int i=0; i<10; ++i)
    {
        cin >> vect->at(i);
    }

    LinearSearch* ls1 = new LinearSearch();
    ls1->setNumberToSearch(num);
    ls1->setNumbersVector(vect);

    int pos = ls1->linearSearch();
    if (pos >=0 &&  pos < 10)
    {
        cout << "\n" << ls1->getNumberToSearch() << " is present at location " <<  pos+1 << endl;
    }
    else
    {
        cout << "\n" << ls1->getNumberToSearch() << " is not present in the vector" << endl;
    }

    delete(ls1);
    
    return 0;
}