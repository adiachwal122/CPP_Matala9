#include "TestCase.hpp"
using namespace std;

TestCase :: TestCase(const string& st , ostream& out)
                    : massaege(st), output(out), fail(0), pass(0), all(0){}

void TestCase :: print() const{
    output << massaege  << ": " << fail <<  " failed, " ;
    output << pass << " passed, " << all << " total." << endl << "---" << endl;
}