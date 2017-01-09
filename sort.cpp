#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int pivotfromleft(int nums[], int left, int right);
int pivotfromright(int nums[], int left, int right);
void quicksort(int nums[], int left, int right);
void swap(int &a, int &b);

int pivotfromleft(int nums[], int left, int right)
{
    if(left < right)
    {
        int tmpVal = nums[left];
        while(left < right)
        {
            while(tmpVal < nums[right] && left < right)
            {
                right--;
            }
            if(left < right)
            {
                nums[left++] = nums[right];
            }
            while(nums[left] < tmpVal && left < right)
            {
                left++;
            }

            if(left < right)
            {
                nums[right--] = nums[left];
            }
        }
        nums[left] = tmpVal;
    }
    return left;
}

int pivotfromright(int nums[], int left, int right)
{
    int i = left - 1;
    if(left < right)
    {
        for(int j = left; j < right; j++)
        {
            if(nums[j] < nums[right])
            {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);
    }
    return i + 1;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int nums[], int left, int right)
{
    if(left < right)
    {
        int index = pivotfromright(nums, left, right);
        //for(int i = 0; i < 10; i++)
        //{
        //    cout << nums[i] <<",";
        //}
        //cout << endl;
        quicksort(nums, left, index - 1);
        quicksort(nums, index + 1, right);
    }
}



void quicksort2(int nums[], int left, int right)
{
    if(left < right)
    {
        int index = pivotfromleft(nums, left, right);
        //for(int i = 0; i < 10; i++)
        //{
        //    cout << nums[i] <<",";
        //}
        //cout << endl;
        quicksort2(nums, left, index - 1);
        quicksort2(nums, index + 1, right);
    }
}


int main()
{
    int nums[10] = {8,2,1,3,6,7,4,5,9,0};
    quicksort(nums, 0, 9);

    for(int i = 0; i < 10; i++)
//        printf("%d,", nums[i]);
        cout << nums[i] << ",";
//    printf("\n");
//
    cout << endl;

    int nums1[10] = {8,20,1,9,61,7,4,5,9,0};
    quicksort2(nums1, 0, 9);
    for(int j = 0; j < 10; j++)
        cout << nums1[j] <<"," ;

    return 1;
}

