#include <bits/stdc++.h>
using namespace std;

bool checkMajority(vector<int> &arr, int n, int num)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (num == arr[i])
      count++;
  }
  if (count > n / 2)
    return true;
  return false;
}

int majority_element(vector<int> arr, int n)
{
  if (arr.empty())
    return -1;
  else if (n == 1)
    return arr[0];
  else if (n % 2 == 1)
  {
    if (checkMajority(arr, n, arr[n - 1]))
      return arr[n - 1];
    arr.pop_back();
    n--;
  }
  vector<int> arr2;
  for (int i = 0; i < n; i += 2)
  {
    // if both elements of pair are same keep else discard both
    if (arr[i] == arr[i + 1])
      arr2.push_back(arr[i]);
  }
  return majority_element(arr2, arr2.size());
}
int main()
{

  int n = 11;
  vector<int> arr{7, 7, 5, 2, 5, 5, 4, 5, 5, 5, 7};

  // int n = 10;
  // vector<int> arr{1, 2, 3, 1, 2, 3, 1, 2, 9, 9};

  // phase 1
  int el = majority_element(arr, n);
  cout << "\nCandidate Element " << el << '\n';
  // phase 2
  if (checkMajority(arr, n, el))
    cout << "\nMajority element " << el << "\n";
  else
    cout << "\nNo Majority Element\n";
  cout << endl;

  return 0;
}