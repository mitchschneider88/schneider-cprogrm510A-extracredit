#include <iostream>
#include <dlfcn.h>
#include "DerivedShape.h"

int main()
{
    const char* bluePath {"./dependencies/blue/libDerivedShape.dylib"};
    const char* redPath {"./dependencies/red/libDerivedShape.dylib"};

    int choice {};

    std::cout << "Enter 1 for Blue or 2 for Red\n";

    std::cin >> choice;

    if (choice == 1)
    {
        void* handle = dlopen(bluePath, RTLD_NOW);

        if (!handle)
        {
            std::cout << "Failed to load handle\n";
        }

        else
        {
            create_s* create_shape = (create_s*) dlsym(handle, "create");
            const char* dlsym_error = dlerror();

            if (dlsym_error)
            {
                std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
                return 1;
            }

            destroy_s* destroy_shape = (destroy_s*) dlsym(handle, "destroy");
            dlsym_error = dlerror();
            if (dlsym_error)
            {
                std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
                return 1;
            }

            Shape* shape = create_shape();

            std::cout << "The Meaning of Life is: " << shape->meaningOfLife() << '\n';

            destroy_shape(shape);
        }

    }
    else if (choice == 2)
    {
        void* handle = dlopen(redPath, RTLD_NOW);

        if (!handle)
        {
            std::cout << "Failed to load handle\n";
        }

        else
        {
            create_s* create_shape = (create_s*) dlsym(handle, "create");
            const char* dlsym_error = dlerror();

            if (dlsym_error)
            {
                std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
                return 1;
            }

            destroy_s* destroy_shape = (destroy_s*) dlsym(handle, "destroy");

            dlsym_error = dlerror();

            if (dlsym_error)
            {
                std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
                return 1;
            }

            Shape* shape = create_shape();

            std::cout << "The Meaning of Life is: " << shape->meaningOfLife() << '\n';

            destroy_shape(shape);
        }
    }

    return 0;
}