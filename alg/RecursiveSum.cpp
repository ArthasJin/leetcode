#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> array, int stopIndex) {
   if (array.size() == 0 ||
       stopIndex >= array.size()) // so we don't try to access an index that doesn't exist
   {
      return 0;
   }
   if (stopIndex == 0) {
      return array[stopIndex];
   } else {
      return array[stopIndex] + sum(array, stopIndex - 1);
   }
}

