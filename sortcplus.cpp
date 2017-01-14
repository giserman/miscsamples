#include <iostream>
#include <array>
#include <vector>

using namespace std;

template <typename T>
void PrintData(const vector<T>& data)
{
    for(typename vector<T>::const_iterator it = data.begin(); it != data.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
}

template<typename T>
class Sort
{
    private:
        int Partition(vector<T>& data, int startindex, int endindex);
    public:
        void BubbleSort(vector<T>& data);
        void InsertSort(vector<T>& data);
        void SelectSort(vector<T>& data);
        void QuickSort(vector<T>& data, int startindex, int endindex);
        void QuickSort2(vector<T>& data, int startindex, int endindex);

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
int Sort<T>::Partition(vector<T>& data, int startindex, int endindex)
{
    T pivotvalue = data[endindex];
    int i = startindex - 1;
    int j = startindex;
    for(;j < endindex; j++)
    {
        if(data[j] <= pivotvalue)
        {
            i = i + 1;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[j], data[endindex]);
    return 1;
}

template <typename T>
void Sort<T>::QuickSort2(vector<T>& data, int startindex, int endindex)
{
    if(startindex < endindex)
    {
        int pivot = Partition(data, startindex, endindex);
        QuickSort2(data, startindex, pivot - 1);
        QuickSort2(data, pivot + 1, endindex);
    }
}



int main()
{
    Sort<int> objsort;
    const int data[] = {1,90,3,19,54,55,6,31,7,9,2,9,19};

    vector<int> vdata(data, data + sizeof(data)/sizeof(data[0]));
    cout << "source data:";
    PrintData(vdata);

    //objsort.BubbleSort(vdata);
    //PrintData(vdata);

    //vector<int> vdata2 = {5,23,1,4,10,22,54,123,101};
    vector<int> vdata2(data, data + sizeof(data)/sizeof(data[0]));
    objsort.BubbleSort(vdata2);
    cout << "bullesort:";
    PrintData(vdata2);

    vector<int> vdata3(data, data + sizeof(data) / sizeof(data[0]));
    objsort.InsertSort(vdata3);
    cout << "InsertSort:";
    PrintData(vdata3);

    vector<int> vdata4(data, data + sizeof(data) / sizeof(data[0]));
    objsort.InsertSort(vdata4);
    cout << "SelectSort:";
    PrintData(vdata4);

    vector<int> vdata5(data, data + sizeof(data) / sizeof(data[0]));
    objsort.QuickSort(vdata5, 0, vdata5.size() - 1);
    cout << "QuickSort:";
    PrintData(vdata5);

    vector<int> vdata6(data, data + sizeof(data) / sizeof(data[0]));
    objsort.QuickSort(vdata6, 0, vdata6.size() - 1);
    cout << "QuickSort2:";
    PrintData(vdata6);
    return 1;
}
