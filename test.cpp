#include <random>
#include <iostream>
#include <ctime>

int main(void)
{
    time_t  t;
    srand(time(&t));
    int c = rand() % 2;
    std::cout << c << "\n";
    std::cout << "Time: " << t << "\n";
}