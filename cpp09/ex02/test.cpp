#include <vector>
#include <algorithm>
#include <iostream>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(20);
	vec.push_back(21);
	vec.push_back(30);
	int val = 19;
	std::vector<int>::iterator upper = std::upper_bound(vec.begin(), vec.end(), val);
	std::vector<int>::iterator lower = std::lower_bound(vec.begin(), vec.end(), val);
	std::cout << "Lower bound: " << static_cast<double>(*lower) << " and upper bound: " << static_cast<double>(*upper) << " for value: " << val <<  "\n";
	vec.insert(upper, val);
	std::for_each(vec.begin(), vec.end(), [](int& x) {std::cout << x << "\n";});
}