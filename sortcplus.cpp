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

        void PrintData(const vector<T>& data);
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
    if (startindex >= endindex)
        return;

    int pivotvalue = data[endindex];
    int i = startindex;
    int j = endindex - 1;
    while(i < j)
    {
        while(i < j && data[i] <= pivotvalue)
        {
            i++;
        }
        while(i < j && data[j] > pivotvalue)
        {
            j--;
        }
        if(i >= j )
        {
            break;
        }
        std::swap(data[i], data[j]);
    }

    if(data[j] > data[endindex])
        std::swap(data[j], data[endindex]);

    //PrintData(data);
    QuickSort(data, startindex, j - 1);
    QuickSort(data, j + 1, endindex);
}

template <typename T>
void Sort<T>::PrintData(const vector<T>& data)
{
    for(vector<int>::const_iterator it = data.begin(); it != data.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
}


int main()
{
    Sort<int> objsort;
    const int data[] = {1,90,3,19,54,55,6,31,7,9,2,9,19};
    vector<int> vdata(data, data + sizeof(data)/sizeof(data[0]));
    cout << "source data:";
    for(vector<int>::const_iterator it = vdata.begin(); it != vdata.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

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

    vector<int> vdata5(data, data + sizeof(data) / sizeof(data[0]));
    objsort.QuickSort(vdata5, 0, vdata5.size() - 1);
    cout << "QuickSort:";
    for(vector<int>::const_iterator it = vdata5.begin(); it != vdata5.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 1;
}
