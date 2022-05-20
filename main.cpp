#include <iostream>
#include <powercgf.h>
#include <cxxopts.hpp>

using namespace std;

int main(int argc, char **argv) {
    try{
        cxxopts::Options opts("WinControl", "Change windows settings with the commandline");

        opts.add_options()
            ("h,help", "Show this help");
        
        opts.add_options("powercgf")
            ("p,plan", "Set powerplan", cxxopts::value<string>())
            ("high-performance", "Set high performance powerplan",cxxopts::value<bool>()->default_value("false"))
            ("power-save", "Set power saving profile", cxxopts::value<bool>()->default_value("false"));

        cxxopts::ParseResult result = opts.parse(argc, argv);

        if(result.count("help")){
            cout << opts.help() << endl;
            return 0;
        }

        switch(argc){
            case 1:
                cout << "Specify a main function as the first argument";
                return -1;
            case 2:
                cout << "Not enough arguments";
                return -1;
        }

        string mainOpt(*(argv+1));

        if(mainOpt.compare("powercgf") == 0){
            
            powercgf::Status state;
            
            if(result.count("high-performance")){
                powercgf::SetMaxPerformancePlan(&state);
            }else if(result.count("power-save")){
                powercgf::SetMaxPowerSavingPlan(&state);
            }

            if(state.success){
                cout << "Successfully set plan." << endl;
            }else{
                cout << "Setting faild." << endl;
            }
        }
    }catch (const cxxopts::OptionException& e){
        std::cout << "error parsing options: " << e.what() << std::endl;
        exit(1);
    }
}