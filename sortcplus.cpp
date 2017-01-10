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
        void QuickSort(vector<T>& data, int startindex, int endindex);
};

template<typename T>
void Sort<T>::BubbleSort(vector<T>& data)
{
    if(data.empty())
    {
        cout << "the data is empty" << endl;
        return;
    }
    std::size_t size = data.size();
    for(unsigned int i = 0; i < size; i++)
    {
        for(unsigned int j = 0; j < size - i - 1; j++)
        {
            if(data[j] > data[j+1])
            {
                std:swap(data[j], data[j+1]);
            }
        }
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
    std::size_t size = data.size();
    for(int i = 1; i < size; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(data[j+1] < data[j])
            {
                std::swap(data[j+1], data[j]);
            }
        }
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

    std::size_t size = data.size();
    for(int i = 0; i < size; i++)
    {
        int tmpIndex = 0;
        for(int j = 1; j < size; j++)
        {
            if(data[tmpIndex] > data[j])
            {
                tmpIndex = j;
            }
        }
        if(tmpIndex != 0)
            std::swap(data[tmpIndex], data[size - i - 1]);
    }
}

template<typename T>
void Sort<T>::QuickSort(vector<T>& data, int startindex, int endindex)
{

}

int main()
{
    Sort<int> objsort;
    const int data[] = {1,90,3,19,54,55,6,31,7,9};
    vector<int> vdata(data, data + sizeof(data)/sizeof(data[0]));
    objsort.BubbleSort(vdata);
    for(vector<int>::const_iterator it = vdata.begin(); it != vdata.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    vector<int> vdata2 = {5,23,1,4,10,22,54,123,101};
    objsort.BubbleSort(vdata2);
    cout << "bullesort:";
    for(vector<int>::const_iterator it = vdata2.begin(); it != vdata2.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    vector<int> vdata3(data, data + sizeof(data) / sizeof(data[0]));
    objsort.InsertSort(vdata3);
    cout << "InsertSort:";
    for(vector<int>::const_iterator it = vdata3.begin(); it != vdata3.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    vector<int> vdata4(data, data + sizeof(data) / sizeof(data[0]));
    objsort.InsertSort(vdata4);
    cout << "SelectSort:";
    for(vector<int>::const_iterator it = vdata4.begin(); it != vdata4.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 1;
}
