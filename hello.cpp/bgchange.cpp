#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <format> // For std::format
#include <emscripten.h>

static bool initialized = false;
extern "C"
{

    int EMSCRIPTEN_KEEPALIVE main()
    {
        std::cout << "WASM is running!" << std::endl;

        if (!initialized) {
            srand(time(NULL));  // Initialize random seed only once
            initialized = true;
        }
        int color_idx = rand() % 3; // could be 0, 1 or 2

        EM_ASM_(
            // here you can write inline javascript code!
            console.log("(1) I have been printed from inline JavaScript!");
            console.log("I have no parameters and I do not return anything :(");
            // end of javascript code
        );

        // note the underscore and the curly brackets (to pass one or more parameters)
        EM_ASM({
        console.log("(2)  I have received a parameter! It is:", $0);
        console.log("Setting the background to that color index!");
        set_background_color($0); }, color_idx);

        // note that you have to specify the return type after EM_ASM_
        int result = EM_ASM_INT({
        console.log("(3) I received two parameters! They are:", $0, $1);
        console.log("Let's return their sum!");
        return sum($0, $1);

        function sum(a, b){
            return a + b;
        } }, 13, 10);

        std::cout << std::format("(4) The C code received {} as result!\n", result);
        return 0;
    }
}
//m++ bgchange.cpp -o bg.html -s EXPORTED_RUNTIME_METHODS='["cwrap","ccall"]' -std=c++20   