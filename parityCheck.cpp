#include <iostream>
#include <bitset> 
using namespace std;


int countBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}


int parityChecker(int n)
{
    int count = countBits(n);
    return count % 2; 
}

int main()
{
    int n = 5;

    cout << "Binary representation of " << n << " is: " << bitset<8>(n) << endl;
    
    
    cout << "Number of 1 bits: " << countBits(n) << endl;

    if (parityChecker(n))
        cout << "Odd parity" << endl;
    else
        cout << "Even parity" << endl;

    return 0;
}
