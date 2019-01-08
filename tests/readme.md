# How to run the Unit Tests ?

The tests are written using [Catch2]()

To run the tests :

1. cd into the `tests/` directory. There is a `CMakeLists.txt` file here.
2. make a directory `build` (just for organization purpose) and cd into the `build` directory
3. run `cmake ..`  -- this will generate the `Makefile`
5. Then run `make`
6. The binary `phs_tests` will be built, run `./phs_tests` to execute the binary.

> NOTE: The instructions here are linux specific.