#include <iostream>
#include <vector>
#include <stdexcept>

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> iv(arr, arr + 10);
    int *p = new int(iv.size());
    try {
        throw std::runtime_error("error occure!");
    } catch(const std::exception &e) {
        delete [] p;
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
