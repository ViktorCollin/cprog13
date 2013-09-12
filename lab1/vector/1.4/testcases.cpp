#include "vector.h"
#include <iostream>

using namespace std;

int main(){
	cout << "--- Testting defult Constructor ---" << endl;
	Vector v1;
	cout << "v1 has size: " << v1.size() << " and are: " << v1 << endl;
	cout << "--- Testting Constructor(0) ---" << endl;
	Vector v2(0);
	cout << "v2 has size: " << v2.size() << " and are: " << v2 << endl;
	cout << "--- Testting Constructor(10) ---" << endl;
	Vector v25(10);
	cout << "v25 has size: " << v25.size() << " and are: " << v25 << endl;
	cout << "--- Testting initilizer-list Constructor ---" << endl;
	Vector v3({1, 2, 3, 4, 5});
	cout << "v3 has size: " << v3.size() << " and are: " << v3 << endl;
	cout << "--- Testting copy Constructor ---" << endl;
	Vector v4(v3);
	cout << "v4 has size: " << v4.size() << " and are: " << v4 << endl;
	cout << "v3 has size: " << v3.size() << " and are: " << v3 << endl;
	cout << "--- Testting move Constructor ---" << endl;
	Vector v5 = std::move(v3);
	cout << "v5 has size: " << v5.size() << " and are: " << v5 << endl;
	cout << "v3 has size: " << v3.size() << " and are: " << v3 << endl;
	
	cout << "--- Testting copy Operator ---" << endl;
	v1 = v5;
	cout << "v1 has size: " << v1.size() << " and are: " << v1 << endl;
	cout << "v5 has size: " << v5.size() << " and are: " << v5 << endl;
	v1 = v1;
	cout << "v1 has size: " << v1.size() << " and are: " << v1 << endl;
	v1 = v25;
	cout << "v1 has size: " << v1.size() << " and are: " << v1 << endl;
	cout << "v5 has size: " << v5.size() << " and are: " << v5 << endl;
	cout << "v25 has size: " << v25.size() << " and are: " << v25 << endl;
	cout << "--- Testting move Operator ---" << endl;
	v1 = std::move(v5);
	cout << "v1 has size: " << v1.size() << " and are: " << v1 << endl;
	cout << "v5 has size: " << v5.size() << " and are: " << v5 << endl;
	cout << "--- Testting initilizer  Operator ---" << endl;
	v5 = {2, 3, 4};
	cout << "v5 has size: " << v5.size() << " and are: " << v5 << endl;
	cout << "--- Testting []  Operator ---" << endl;
	v5[0] = 1;
	cout << "v5 has size: " << v5.size() << " and are: " << v5 << endl;
	
	
	
	 
}