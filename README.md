# TestlibAugment
A short code to automatically turn a testlib.h checker into a Themis-compatible checker

## Usage

Step 1: Clone this repo with ```git clone --recurse-submodules <git url>```.

Step 2: Change ```#include "testlib.h``` in your checker to ```#include "themistestlib.h"```.

Step 3: Compile and you're ready to go.
