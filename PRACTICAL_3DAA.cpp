#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

//------------- MAX HEAPIFY -------------//
void maxHeapify(vector<int> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

//------------- MAX HEAP SORT -------------//
void maxHeapSort(vector<int> &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

//------------- MIN HEAPIFY -------------//
void minHeapify(vector<int> &a, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

//------------- MIN HEAP SORT -------------//
void minHeapSort(vector<int> &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }

    reverse(a.begin(), a.end());
}

//------------- MAIN FUNCTION -------------//
int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> data(n);

    srand(time(0));

    for (int i = 0; i < n; i++)
        data[i] = rand() % 100000;

    vector<int> maxData = data;
    vector<int> minData = data;

    // MAX HEAP SORT
    auto startMax = high_resolution_clock::now();

    maxHeapSort(maxData);

    auto endMax = high_resolution_clock::now();

    // MIN HEAP SORT
    auto startMin = high_resolution_clock::now();

    minHeapSort(minData);

    auto endMin = high_resolution_clock::now();

    auto maxNano = duration_cast<nanoseconds>(endMax - startMax);
    auto maxMicro = duration_cast<microseconds>(endMax - startMax);

    auto minNano = duration_cast<nanoseconds>(endMin - startMin);
    auto minMicro = duration_cast<microseconds>(endMin - startMin);

    cout << "\n============ MAX HEAP SORT ============\n";
    cout << "Execution Time (Nanoseconds)  : " << maxNano.count() << endl;
    cout << "Execution Time (Microseconds) : " << maxMicro.count() << endl;

    cout << "\n============ MIN HEAP SORT ============\n";
    cout << "Execution Time (Nanoseconds)  : " << minNano.count() << endl;
    cout << "Execution Time (Microseconds) : " << minMicro.count() << endl;

    cout << "\n=== Code Execution Successful ===";

    return 0;
}

OUTPUT

Enter the number of elements: 7

============ MAX HEAP SORT ============
Execution Time (Nanoseconds)  : 1290
Execution Time (Microseconds) : 1

============ MIN HEAP SORT ============
Execution Time (Nanoseconds)  : 1200
Execution Time (Microseconds) : 1

=== Code Execution Successful ===