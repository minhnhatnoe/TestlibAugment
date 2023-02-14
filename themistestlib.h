#include <iostream>
#include "testlib/testlib.h"

namespace _themis{
    long double result = -1;
    char problem_name[1000];

    char test_data[1000], cwd[1000];
    char input_file[1000], output_file[1000], answer_file[1000];

    char* argv_new[4] = {test_data, input_file, output_file, answer_file};

    void get_problem_name(const char *path){
        char* start = strrchr(path, '\\')+6; // Skips "\Check"
        char* end = strrchr(path, '.'); // 

        char *buffer;
        for (buffer=problem_name; start != end; start++, buffer++)
            *buffer = *start;
        *buffer = 0;
    }
    void themis_init(){
        std::cin >> test_data >> cwd;
        get_problem_name(__BASE_FILE__);

        snprintf(input_file, 1000, "%s%s.inp", test_data, problem_name);
        snprintf(output_file, 1000, "%s%s.out", cwd, problem_name);
        snprintf(answer_file, 1000, "%s%s.out", test_data, problem_name);

        dup2(STDOUT_FILENO, STDERR_FILENO);
        registerTestlibCmd(4, argv_new);
    }
    void quitf_other(TResult r, const char *msg, ...){
        FMT_TO_RESULT(msg, msg, message);
        if (r == _ok){
            result = 1;
            quitf(_ok, (message + "\n" + std::to_string(result)).c_str());
        }
        if (r >= _partially)
            result = (r-_partially)/200.L;
        else
            result = 0;
        std::cout << message << "\n" << std::to_string(result) << "\n";
        _exit(0);
    }
}
#define quitf _themis::quitf_other
#define registerTestlibCmd(argc, argv) _themis::themis_init()
