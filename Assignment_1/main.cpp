// C++ program to find out execution time ofof functions
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

int main()
{   
    int Max_size = 250;
    vector<vector<int>> Result(3, vector<int>(Max_size, 0));
    for (int n = 1; n <= Max_size; n++)
    {
        vector<vector<float>> A(n, vector<float>(n)), B(n, vector<float>(n)), C(n, vector<float>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = rand() % 10000;
                B[i][j] = rand() % 10000;
            }
        }
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                }
            }
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
        Result[0][n - 1] = n;
        Result[1][n - 1] = duration;
        Result[2][n - 1] = (n * n) * (2 * n - 1);
        
    }
    
    plt::figure_size(900, 700);
    plt::xlim(1, Max_size);
    plt::xlabel("Size of Square-Matrix");
    plt::ylabel("Execution Time (in microseconds)");
    plt::title("Execution Time vs Size");
    plt::plot(Result[0],Result[1],{{"color", "red"}});

    plt::figure_size(900, 700);
    plt::xlim(1, Max_size);
    plt::xlabel("Size of Square-Matrix");
    plt::ylabel("Number of Operations");
    plt::title("No of Operations vs Size");
    plt::plot(Result[0],Result[2],{{"color", "red"}});
    plt::show();
    return 0;
}
