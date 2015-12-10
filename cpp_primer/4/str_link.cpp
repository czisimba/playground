#include <iostream>
using namespace std;

#define MAX_STR 100
int main()
{
    // c type str link
    char str1[MAX_STR] = "nihao";
    char str2[MAX_STR] = "world";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    strcpy(str1 + len1, str2);
    printf("c new str:%s\n", str1);

    string cpp_str1("nihao");
    string cpp_str2("world");
    cpp_str1 += cpp_str2;
    cout << "c++ new str:" << cpp_str1 << endl;


    return 0;
}
