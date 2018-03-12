# T10 Calculator 01

## Building

Currently, the recommended method to build T10 is to just use Qt Creator's build tools.

The other option to build is to use `build.sh`. Running this shell script (like `. build.sh`) while in the root repo directory will copy the repo to a different directory (after cleaning it), build it, and then run it. The build directory can be configured by setting the `CALC01_BUILD` environment variable.

## CI

Currently, CI will only attempt to build the project. If this build succeeds, we're good to go. In the future, CI will also run tests on the project before giving the green light.

The script used to build is currently just `qmake && make all`. Eventually, CI will probably just use `build.sh`.
