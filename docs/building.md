# Building Calc01

## Qt Creator build tools

The easiest way to build the project is to simply use Qt Creator's internal build tools. Post-ExprTk, building takes a lot of memory, so make sure you have a good computer.

## `build.sh` (Mac and Linux)

The best-supported way of building is to use the included build script by running `. build.sh` while inside the project folder. This copies the project to a separate folder before building the project. The default folder is `~/SDRIVE/cs3100/calc01-build`, but this can be changed by setting the environment variable `CALC01_BUILD`.

Passing verbs to `build.sh` when you run it (for instance, `. build.sh <verb>`) changes what steps the script completes.

* `setup`: Creates the build folder if it doesn't already exist.
* `clean`: Cleans the build folder (calls `setup`).
* `build` (default): Copies the project to the build folder and compiles it (calls `clean`).
* `run`: Runs the project (calls `build`).
* `test` (todo): Builds and tests the project (calls `clean`).
* `runonly` (todo): Runs the previously-built project.

Note that if you are attempting to `run` the calculator over ssh (PuTTY), the compiled program will abort if it cannot connect to a GUI. You must have X installed and running on your system and X-forwarding enabled in your ssh connection in order to run over ssh.

Again, post-ExprTk, building takes a lot of memory and a lot of time. Nicole timed the build process on the CS Linux machines to take 17 minutes, so be patient. CI is on a pretty beefy computer so the build process should only take a few minutes there.

## Dependencies

You must have Qt 5.5 installed on your system or this will not build. Additionally, make sure you have a modern g++ compiler installed.
