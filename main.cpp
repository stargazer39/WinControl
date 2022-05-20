#include <iostream>
#include <powercgf.h>

using namespace std;

int main(int argc, char **argv) {
    powercgf::Status state;

    powercgf::SetMaxPerformancePlan(&state);


    if(state.success){
        cout << "Successfully SetMaxPerformancePlan" << endl;
    }else{
        cout << "SetMaxPerformancePlan faild." << endl;
    }
}