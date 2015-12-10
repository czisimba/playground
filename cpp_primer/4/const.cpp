#include <iostream>
using std::cout;
using std::endl;

int i;
const int ic = i;
const int *pic = &ic;
int *const cpi = &i;
const int *const cpic = &ic;

int main()
{
    const double pi = 3.1415;
    const double *pi_ptr = &pi;
    
    cout << *pi_ptr << endl;

    return 0;
}
