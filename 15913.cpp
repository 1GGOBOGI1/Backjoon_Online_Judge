#include <random>
#include<iostream>
using namespace std;
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 2);
    int judge = distribution(gen);
    cout<<judge<<endl;
    return 0;
}