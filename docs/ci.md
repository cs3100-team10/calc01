# CI

Currently, CI will only attempt to build the project. In the near future, when we finally have tests, CI will also run those.

If the build succeeds, the associated commit will receive a green checkmark. If the build fails, the commit will have a red X.

Currently, the script being used to build is simply `qmake && make all`. Eventually, CI will either use `build.sh` or a similar script.

The build process takes awhile with ExprTk, but CI runs on a strong computer so the build process won't take a ridiculously long time.
