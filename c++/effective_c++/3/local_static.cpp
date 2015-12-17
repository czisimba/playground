#include <iostream>

class Filesystem {
public:
    std::size_t numDisks() {
        return 0;
    }
};

Filesystem& tfs()
{
    static Filesystem fs;
    return fs;
}

class Directory {
    std::size_t disks = tfs().numDisks();
};

Directory& tempDir()
{
    static Directory td;
    return td;
}

int main() {
    return 0;
}
