#!/bin/bash

# Get the current directory
dev_dir="$(cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)"

# Get a separate directory to build in.
# By default, builds in "~/SDRIVE/cs3100/calc01-build"
# Can be reconfigured with an environment variable CALC01_BUILD.
build_dir=${CALC01_BUILD:-"$HOME/SDRIVE/cs3100/calc01-build"}

## SETUP
#  Ensures that there is a build directory.
function setup()
{
  # Has the build directory already been created?
  if [[ -d "$build_dir" ]]; then
    # Yes, so just announce it
    echo "setup: building in $build_dir"

  else
    # No, so create it
    echo "setup: making build directory at $build_dir"
    mkdir -p "$build_dir"

  fi

}

## CLEAN
#  Cleans the build directory.
function clean()
{

  # prep
  setup

  # First make sure the build dir is clean
  echo "clean: cleaning"
  rm -rf $build_dir/*

}

## BUILD
#  The bulk of the build logic. Most of the other tasks
function build()
{

  # Copy over the current directory
  echo "build: copying"
  cp -ur $dev_dir/* $build_dir

  # Move to build directory
  cd "$build_dir"

  # Build
  echo "build: qmake"
  qmake

  sleep 1 # otherwise we might invent time travel

  echo "build: make all"
  make all

  cd "$dev_dir"

}

## RUN
#  Run the project.
function run()
{

  # Prep
  build

  # Run
  echo "run: $build_dir/T10Calculator"
  $build_dir/T10Calculator
}

case "$1" in
  clean)
    clean
    ;;
  
  build)
    build
    ;;
  
  run)
    run
    ;;
  
  *)
    build
    ;;
esac
