#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[r]); 
    return i; 
} 
  
int kthSmallest(vector<int> &arr, int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) { 
  
        int index = partition(arr, l, r); 
        if (index - l == k - 1) 
            return arr[index]; 

        if (index - l > k - 1)  
            return kthSmallest(arr, l, index - 1, k); 

        return kthSmallest(arr, index + 1, r,  
                            k - index + l - 1); 
    } 
    return -1; 
} 
  
int main()
{
    for (int n = 5; n <= 10; n++)
    {
        vector<int> arr(n);
        cout << " Test " << n - 5<< "\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 1000;
            cout << arr[i] << '\t';
        }
        cout << "\n" <<endl;
        int k = rand() % (n - 1) + 1;
        int num = kthSmallest(arr, 0, n - 1,k);
        cout << k <<"th smallest element in Array of size " << n << " is "<<num<<"\n";
        // sort(arr.begin(),arr.end());
        for(int i = 0; i < n ; i++)
        {
            cout << arr[i] << '\t';
        }
        cout << "\n" <<endl;
    }

    return 0;
}
