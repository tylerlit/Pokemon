#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  

  int size = 10;

  vector<int> young(size);
  vector<int> old;
  
  for (int i = 0; i < size; i++) {
    young[i] = i;
  }

  for (unsigned int j = 0; j < young.size(); j++) {
  
    bool sexy = (rand() % 101) <= 10;

    if (sexy) {
      old.push_back(young[j]);
    }
  }

  for (unsigned int k = 0; k < old.size(); k++) {

    cout << old[k] << " ";
  }
}
