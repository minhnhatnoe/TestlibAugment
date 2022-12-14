#include "testlib/testlib.h"
#include <bits/stdc++.h>

namespace _themis{
    char problem_name[1000];
    const char input[] = ".inp", output[] = ".out";

    char test_data[1000], cwd[1000], problem_name[1000];
    char input_file[1000], output_file[1000], answer_file[1000];

    char* argv_new[4] = {test_data, input_file, output_file, answer_file};

    void get_problem_name(const char *path){
        char* start = strrchr(path, '/')+7; // Skips "/Check"
        char* end = strrchr(path, '.'); // 

        char *buffer;
        for (buffer=problem_name; start != end; start++, buffer++)
            *buffer = *start;
        *buffer = 0;
    }
    void themis_init(){
        std::cin >> test_data >> cwd;
        get_problem_name(__FILE__);

        snprintf(input_file, 1000, "%s%s.inp", test_data, problem_name);
        snprintf(output_file, 1000, "%s%s.out", test_data, problem_name);
        snprintf(answer_file, 1000, "%s%s.out", cwd, problem_name);

        registerTestlibCmd(4, argv_new);
    }
    void quitf_other(TResult r, const char *msg, ...){
        FMT_TO_RESULT(msg, msg, message);
        std::cout << message << "\n";
        if (r == _ok)
            std::cout << "1\n";
        else if (r >= _partially)
            std::cout << float(r-_partially)/200 << "\n";
        else
            std::cout << "0\n";
        quitf(_ok, message.c_str());
    }
}
#define quitf _themis::quitf_other
#define registerTestlibCmd(argc, argv) _themis::themis_init()
