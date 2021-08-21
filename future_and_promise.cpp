/*
copyright 2021 Oleksandr Chastukhin

this main goal is to investigane how to pass a variable from one thread to another with std::future and std::promise.

to compile it in Linux use
g++ -pthread -std=c++11

*/
#include <thread>
#include <future> // std::promise, std::future
#include <iostream>

using std::promise;
using std::future;
using std::thread;
using std::cout;
using std::endl;

void another_thread(promise<int> result)
{
    cout <<"the second thread computes the result" << endl;
    result.set_value(1); // // notify future object
    cout <<"the second thread does something else" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "the second thread exits" << endl;
}

int main()
{
    cout << "the main thread works" << endl;

    // another thread will compule this result for us
    promise<int> result;

    // we will get the result in the future
    auto future_result = result.get_future();

    // here we create another thread and move the promise object there
    // we move because std::promose deleted its copy constructor:
    // promise( const promise& other ) = delete;
    thread job(another_thread, std::move(result));

    // get the result from another thread as soon as it is ready for us
    cout << "print the result: " << endl;
    cout << future_result.get() << endl;
    
    // we have to join the thread and wait for it before we exit the app
    // if we don't do that, 'Aborted (core dumped)' will come
    job.join();

    cout << "the main thread exits" << endl;
    return 0;
}

/*
the outcome

the main thread works
print the result: 
the second thread computes the result
the second thread does something else
1
the second thread exits
the main thread exits
done
 */
