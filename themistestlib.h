#include "testlib/testlib.h"
#include <bits/stdc++.h>

namespace _themis{
    char problem_name[1000];
    const char input[] = ".inp", output[] = ".out";

    using namespace std;
    char test_data[1000], cwd[1000], problem_name[1000];
    char input_file[1000], output_file[1000], answer_file[1000];

    char* argv_new[4] = {test_data, input_file, output_file, answer_file};

    void get_problem_name(const char *path){
        int size = strlen(path), ptr=0;
        for (int ptr=size-1; ptr>=0; ptr--){
            if (path[ptr] == '/') break;
        }

        // ptr: /Check*.cpp
        char* buffer=problem_name;
        for (int i=ptr+6; i<size-4; i++, buffer++){
            *problem_name = path[i];
        }
        *buffer = 0;
    }
    void themis_init(){
        cin >> test_data >> cwd;
        get_problem_name(__FILE__);

        strcpy(input_file, test_data), strcat(input_file, problem_name), strcat(input_file, input);
        strcpy(output_file, test_data), strcat(output_file, problem_name), strcat(output_file, output);
        strcpy(answer_file, cwd), strcat(answer_file, output);

        registerTestlibCmd(4, argv_new);
    }
    void quitf_other(TResult r, const char *msg, ...){
        FMT_TO_RESULT(msg, msg, message);
        cout << message << "\n";
        if (r == _ok)
            cout << "1\n";
        else if (r >= _partially)
            cout << float(r-_partially)/200 << "\n";
        else
            cout << "0\n";
        quitf(_ok, message.c_str());
    }
}
#define quitf _themis::quitf_other
#define registerTestlibCmd(argc, argv) _themis::themis_init()
