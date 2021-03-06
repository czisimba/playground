#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>
#include <boost/thread/mutex.hpp>

boost::mutex io_mutex;
class count {
public:
    count(int id):id(id) { }
    void operator()() {
        for (int i = 0;i < 10;++i)
        {
            boost::mutex::scoped_lock lock(io_mutex);
            std::cout << id << ":" << i << std::endl;
        }
    }
private:
    int id;
};

int main()
{
    boost::thread thrd1(count(1));
    boost::thread thrd2(count(2));
    thrd1.join();
    thrd2.join();

    return 0;
}
