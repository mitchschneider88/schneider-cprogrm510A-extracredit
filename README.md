# Schneider - U of W C++ Course 1 Extra Credit

Note: on macOS, dynamic libraries are compiled into files with the extension .dylib

## Load-time dynamic linking: library definitions
### Shape source files exist and compile into a dynamic library. Two derived specializations of Shape exist according to the spec and compile to independent dynamic libraries.

## Load-time dynamic linking: dynamic executable
### Project or makefile exists to compile a LoadTimeLinkedShapes executable. The executable runs unit tests as specified. Two modes of execution exist to use one of the two derived dynamic modules, without requiring recompliation.

In the root directory, run 'make all' to create the dynamic libraries and the LoadTimeLinkedShapes.exe

Next, run 'loadtime-run.sh' to demonstrate manipulating the environment variable to run LoadTimeLinkedShapes.exe in two different modes (one referencing the red .dylib and one referencing the blue .dylib)

## Run-time dynamic linking
### Project or makefile exists to compile a RuntimeLinkedShapes executable. Executable lets the user choose at runtime which dynamic library to use.

In the root directory, run 'make RuntimeLink' to create the RuntimeLinkedShapes.exe

When you run this program, the user will be given the option to select either the blue or red library via the command line

## Static Linking
### Project or makefile exists to compile Shape and one of its specializations into static libraries, and then compile the result into a StaticallyLoadedShapes executable, in one build action. Resulting executable is standalone with no other dependencies.

cd into the 'StaticLibVersion' directory. In this directory, run 'make all' to create the static libraries and the StaticallyLoadedShapes.exe

Next, run staticlib-run.sh to demonstrate you can delete the static libraries and still run StaticallyLoadedShapes.exe successfully

#### Resources:

https://tldp.org/HOWTO/C++-dlopen/thesolution.html
https://amir.rachum.com/shared-libraries/#runtime-search-path
https://domiyanyue.medium.com/c-development-tutorial-4-static-and-dynamic-libraries-7b537656163e
