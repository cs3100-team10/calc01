#!/bin/bash

# Get the current directory
dev_dir=`pwd`

# Get a separate directory to build in.
# By default, builds in "~/SDRIVE/cs3100/calc01-build"
# Can be reconfigured with an environment variable CALC01_BUILD.
build_dir=${CALC01_BUILD:-"$HOME/SDRIVE/cs3100/calc01-build"}

# Has the build directory already been created?
if [[ -d "$build_dir" ]]; then
  # Yes, so just announce it
  echo "calc01-build: building in $build_dir"

else
  # No, so create it
  echo "calc01-build: making build directory at $build_dir"
  mkdir -p "$build_dir"

fi

# First make sure the build dir is clean
echo "calc01-build: cleaning"
rm -rf $build_dir/*

# Copy over the current directory
echo "calc01-build: copying"
cp -r $dev_dir/* $build_dir

# Move to build directory
cd "$build_dir"

# Build
echo "calc01-build: qmake"
qmake

sleep 1 # otherwise we might invent time travel

echo "calc01-build: make all"
make all

# Run the calculator
# Note that when the user does this, the script will pause at this point
# until the user closes the calculator
# TODO: Allow the user to just attempt to compile and not run
echo "calc01-build: ./T10Calculator"
./T10Calculator

# Return to dev directory
cd "$dev_dir"
