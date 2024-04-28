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

int binarysearch(vector<int> &A, int target)
{
    int low = 0 ,high = A.size() - 1; 
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == target)
        {
            return mid;
        }
        else if (A[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    random_device rad;
    mt19937 gen(rad());
    int low_size = 10000;
    int Max_size = INT16_MAX - low_size;
    vector<vector<int>> Result(2, vector<int>(Max_size, 0));
    for (int size = low_size; size <= Max_size; size++)
    {
        vector<int> A(size);
        int h = INT_MAX, l = 0;
        for (int i = 0; i < size; i++)
        {
            int num = gen() % (h - l + 1) + 1;
            A[i] = num;
        }
        sort(A.begin(), A.end());
        int target = A[gen() % size];

        auto start = chrono::high_resolution_clock::now();
        int result = binarysearch(A, target);
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
        Result[0][size - 1 - low_size] = size;
        Result[1][size - 1 - low_size] = duration;
    }

    plt::figure_size(1800, 1000);
    plt::xlim(low_size, Max_size);
    plt::xlabel("Size of Input Array");
    plt::ylabel("Execution Time (in microseconds) ");
    plt::title("Execution Time vs Size");
    plt::plot(Result[0],Result[1],{{"color", "red"}});
    plt::show();

    return 0;
}