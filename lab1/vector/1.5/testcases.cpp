#include "vector.h"
#include <iostream>

using namespace std;

int main(){
  cout << "--- Init vector {1, 2, 3, 4} ---" << endl;
  Vector<int> v1 = {1, 2, 3, 4};
  cout << "v1 has size: " << v1.size() << " and maxSize: " << v1.maxSize() << " and are: " << v1 << endl;
  cout << "--- push_back (5) ---" << endl;
  v1.push_back(5);
  cout << "v1 has size: " << v1.size() << " and maxSize: " << v1.maxSize() << " and are: " << v1 << endl;
  cout << "--- insert(3, 10) ---" << endl;
  v1.insert(3, 10);
  cout << "v1 has size: " << v1.size() << " and maxSize: " << v1.maxSize() << " and are: " << v1 << endl;
  cout << "--- erase(3) ---" << endl;
  v1.erase(3);
  cout << "v1 has size: " << v1.size() << " and maxSize: " << v1.maxSize() << " and are: " << v1 << endl;
  cout << "--- exists(3) ---" << endl;
  cout << "result was: " << v1.exists(3) << endl;
  cout << "v1 has size: " << v1.size() << " and maxSize: " << v1.maxSize() << " and are: " << v1 << endl;
  cout << "--- exists(10) ---" << endl;
  cout << "result was: " << v1.exists(10) << endl;
  cout << "v1 has size: " << v1.size() << " and maxSize: " << v1.maxSize() << " and are: " << v1 << endl;
  //cout << "--- sort(false) ---" << endl;
  //v1.sort(false);
  //cout << "v1 has size: " << v1.size() << " and maxSize: " << v1.maxSize() << " and are: " << v1 << endl;
  //cout << "--- sort() ---" << endl;
  //v1.sort();
  //cout << "v1 has size: " << v1.size() << " and maxSize: " << v1.maxSize() << " and are: " << v1 << endl;
  cout << "--- Init vector v2 {1, 2, 3, 4} ---" << endl;
  Vector<int> v2 = {1, 2, 3, 4};
  cout << "v2 has size: " << v2.size() << " and maxSize: " << v2.maxSize() << " and are: " << v2 << endl;
  v2.insert(1,5); 
  cout << "v2 has size: " << v2.size() << " and maxSize: " << v2.maxSize() << " and are: " << v2 << endl;

  return 0;	 
}
