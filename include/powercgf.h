#pragma once

#include <iostream>
#include <windows.h>
#include <powersetting.h>
#pragma comment(lib, "powrprof.lib")

namespace powercgf {
    class Status {
        public:
            boolean success = false;
            DWORD dword = NULL;
            Status();
            Status(boolean success, DWORD dword);
    };
    void sayHello();
    void SetMaxPowerSavingPlan(Status* status);
    void SetMaxPerformancePlan(Status* status);
}

