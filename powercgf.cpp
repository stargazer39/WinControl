#include <powercgf.h>

namespace powercgf {
    Status::Status() {};

    Status::Status(boolean success, DWORD dword){
        this->success = success;
        this->dword = dword;
    }
    
    void sayHello() {
        std::cout << "Hello form powercgf" << std::endl;
    }

    void SetMaxPerformancePlan(Status* status) {
        DWORD res = PowerSetActiveScheme(NULL, &GUID_MIN_POWER_SAVINGS);

        status->success = (res == ERROR_SUCCESS);
        status->dword = res;
    }

    void SetMaxPowerSavingPlan(Status* status) {
        DWORD res = PowerSetActiveScheme(NULL, &GUID_MIN_POWER_SAVINGS);

        status->success = (res == ERROR_SUCCESS);
        status->dword = res;
    }
}
