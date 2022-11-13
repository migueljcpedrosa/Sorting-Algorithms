#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int temp = v[i];

        int j;
        for ( j = i; j > 0 && temp < v[j - 1]; j--)
        {
            v[j] = v[j-1];
        }
        v[j] = temp;
    }
}

void selectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int indexMin = i;

        int j;
        for (j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[indexMin])
            {
                indexMin = j;
            }
        }
        swap(v[i], v[indexMin]);
    }
}

void bubbleSort(vector<int> &v)
{
    bool isSorted;

    for (int i = v.size() - 1; i > 0; i--)
    {
        isSorted = true;
        for (int j = 0; j < i; j++)
        {
            if (v[j + 1] < v[j])
            {
                swap(v[j], v[j + 1]);
                isSorted = false;
            }
        }

        if (isSorted)
        {
            return;
        }
    }

}

void shellSort(vector<int> &v)
{
    int j;
    int temp;

    for (int gap = v.size()/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < v.size(); i++)
        {
            temp = v[i];
            for (j = i; j >= gap && temp < v[j-gap]; j -= gap)
            {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}

void merge(vector <int> &v, vector<int> &tempV, int leftPos, int rightPos, int rightEnd)
{
    cout << "entered merge" << endl;
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd)
    {
        if (v[leftPos] <= v[rightPos])
        {
            tempV[tempPos++] = v[leftPos++];
        }
        else
        {
            tempV[tempPos++] = v[rightPos++];
        }
    }

    while (leftPos <= leftEnd)
    {
        tempV[tempPos] = v[leftPos];
        tempPos++;
        leftPos++;
    }

    while (rightPos <= rightEnd)
    {
        tempV[tempPos] = v[rightPos];
        tempPos++;
        rightPos++;
    }

    //place the values from the tempV in their respective positions in V
    for ( int i = 0; i < numElements; i++)
    {
        v[rightEnd] = tempV[rightEnd];
        rightEnd--;
    }
}

void mergeSort(vector<int> &v, vector<int> &tempV, int left, int right)
{
    cout<<"entered mergeSort" << endl;
    //mergeSort calls itself until it reaches structures with only one element
    if (left < right)
    {
        int center = (left + right) / 2;
        mergeSort(v, tempV, left, center);
        mergeSort(v, tempV, center + 1, right);
        merge(v, tempV, left, center + 1, right);
    }
}

const int &median3(vector<int> &v, int left, int right)
{
    int center = (left + right) / 2;
    if (v[center] < v[left])
    {
        swap(v[center], v[left]);
    }
    if (v[right] < v[left])
    {
        swap(v[right], v[left]);
    }
    if (v[right] < v[center])
    {
        swap(v[right], v[center]);
    }
    swap(v[center], v[right - 1]);

    return v[right - 1];
}

void quickSort(vector<int> &v, int left, int right)
{
    if (right - left <= 10)
    {
        insertionSort(v);
    }
    else
    {
        int x = median3(v, left, right);
        int i = left;
        int j = right - 1;

        while(true)
        {
            while (v[++i] < x);
            while (x < v[--j]);

            if (i < j)
            {
                swap(v[i], v[j]);
            }
            else
            {
                break;
            }
        }

        swap(v[i], v[j]);
        quickSort(v, left, i-1);
        quickSort(v, i+1, right);
    }
}

void printVector(vector<int> &v)
{
    cout << "[ ";
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << "]";
}

int main() {
    vector<int> v {1, 5, 7, 2, 4, 3, 5, 1, 9};
    vector<int> v1 {1, 5, 7, 2, 4, 3, 5, 1, 9, 4, 3, 8, 7, 5, 9};
    vector<int> tempV {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int left = 0;
    int right = v.size() - 1;

    //insertionSort(v);
    //selectionSort(v);
    //bubbleSort(v);
    //mergeSort(v, tempV, left, right);
    quickSort(v1, 0, v1.size());
    printVector(v1);
    return 0;
}
