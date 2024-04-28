/*  TO compile 
   g++ main.cpp -o plot  -I/usr/include/python3.10 -I/usr/include/numpy -lpython3.10
  
*/
#include <bits/stdc++.h>
#include <vector>
#include "../matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std;

static const auto init = []{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 std::cout.tie(nullptr);
 return false;
}();

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int Max_size = 1000;
    vector<vector<int>> Result(2, vector<int>(Max_size, 0));
    for (int n = 1; n <= Max_size; n++)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 100000;
        }
        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
        Result[0][n - 1] = n;
        Result[1][n - 1] = duration;
    }
    
    plt::figure_size(1800, 1000);
    plt::xlim(20, Max_size);
    plt::xlabel("Size of Input Array");
    plt::ylabel("Execution Time (in microseconds) ");
    plt::title("Execution Time vs Size");
    plt::plot(Result[0],Result[1],{{"color", "red"}});
    plt::show();

    return 0;
}
