#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <functional>

using namespace std;
///#include "TestCase.cpp"

class TestCase{
    
    protected:
        string massaege;
        int fail, pass, all;
        ostream& output;
    
    
    public:
    
        TestCase(const string& , ostream&);
        TestCase(const TestCase&);


        template<typename T>
        TestCase& check_equal(const T& x, const T& y){
            all++;
            if ((T)x == (T)y)
                pass++;
            else{
                fail++;
                output << massaege << ": Failure in test #" << all;
                output << ": " << y << " should equal " << x << "!" << endl;
            }
            return *this;
        }
    
        template<typename T>
        TestCase& check_different(const T& x, const T& y){
            all++;
            if ((T)x != (T)y)
                pass++;
            else{
                fail++;
                output << massaege << ": Failure in test #" << all;
                output << ":" << y << " shouldn't equal " << x << "!" << endl;
                
            }
            return *this;
        }
        
          template<typename R, typename T1, typename T2>
        TestCase& check_function(R func , const T1& x, const T2& y){
            all++;
            T2 a = func(x);
            if((T2)a != (T2)y){
                fail++;
                output << massaege << ": Failure in test #" << all;
                output << ":" <<  " Function should return " << y << " but returned " << a << "!" <<  endl;
            }
            else{
               pass++;
            }
            
            return *this;
        }
    
        template<typename T>
        TestCase& check_output(const T& x, const string& y){
            stringstream st;
            st << (T)x;
            all++;

            if (y.compare(st.str()) == 0){
                pass++;
            }
            else{
                fail++;
                output << massaege << ": Failure in test #" << all;
                output << ": string value should be " << y << " but is " << x << "!" << endl;
            }
            return *this;
        }
        
     void print() const;   
    
};

