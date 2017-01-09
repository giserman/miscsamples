#include <iostream>
#include <array>
#include <vector>

using namespace std;

template<typename T>
class Sort
{
    public:
        void BubbleSort(vector<T>& data);
        void InsertSort(vector<T>& data);
        void SelectSort(vector<T>& data);
};

template<typename T>
void Sort<T>::BubbleSort(vector<T>& data)
{
    if(data.empty())
    {
        cout << "the data is empty" << endl;
        return;
    }
}

template<typename T>
void Sort<T>::InsertSort(vector<T>& data)
{
    if(data.empty())
    {
        cout << "the data is empty" << endl;
        return;
    }
}

template<typename T>
void Sort<T>::SelectSort(vector<T>& data)
{
    if(data.empty())
    {
        cout << "the data is empty" << endl;
        return;
    }
}


int main()
{
    Sort<int> objsort;
    vector<int> vdata;
    objsort.BubbleSort(vdata);
    return 1;
}
