#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
struct MinHeapNode {
  char data;
  unsigned freq;
  MinHeapNode *left, *right;
  MinHeapNode(char data, unsigned freq) {
    left = right = NULL;
    this->data = data;
    this->freq = freq;
  }
};
struct compare {
  bool operator()(MinHeapNode *l, MinHeapNode *r) {
    return (l->freq > r->freq);
  }
};
void printCodes(struct MinHeapNode *root, string str,
                unordered_map<char, string> &codes) {
  if (!root)
    return;
  if (root->data != '$') {
    cout << root->data << ": " << str << "\n";
    codes[root->data] = str;
  }
  printCodes(root->left, str + "0", codes);
  printCodes(root->right, str + "1", codes);
}

void HuffmanCodes(const string &input) {
  unordered_map<char, int> freq;
  for (size_t i = 0; i < input.length(); ++i) {
    char ch = input[i];
    freq[ch]++;
  }
  priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
  for (auto it = freq.begin(); it != freq.end(); ++it) {
    char character = it->first;
    int frequency = it->second;
    minHeap.push(new MinHeapNode(character, frequency));
  }
  while (minHeap.size() != 1) {
    MinHeapNode *left = minHeap.top();
    minHeap.pop();
    MinHeapNode *right = minHeap.top();
    minHeap.pop();
    MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    minHeap.push(top);
  }
  unordered_map<char, string> codes;
  printCodes(minHeap.top(), "", codes);
  string decodedInput = "";
  string encodedStr = "";
  for (char ch : input) {
    encodedStr += codes[ch];
  }
  cout << "Encoded String: " << encodedStr << endl;
  string currentCode = "";
  for (char bit : encodedStr) {
    currentCode += bit;
    for (auto &pair : codes) {
      if (pair.second == currentCode) {
        decodedInput += pair.first;
        currentCode = "";
        break;
      }
    }
  }
  cout << "Decoded Input String: " << decodedInput << endl;
}
int main() {
  string input = "mathematics";
  HuffmanCodes(input);
  return 0;
}