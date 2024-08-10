#include <iostream>
#include <emscripten.h> // note we added the emscripten header
#include <time.h>
// em++ hello.cpp -o hello.html -s EXPORTED_RUNTIME_METHODS='["cwrap","ccall"]'
extern "C"{
int EMSCRIPTEN_KEEPALIVE fib(int n){
    if(n==1 || n==0){
        return 1;
    } else{
        return fib(n-1) + fib(n-2);
    }
}
void EMSCRIPTEN_KEEPALIVE bg(){
    emscripten_run_script("set_background_color(1)");
}
int main(){
std::cout << "Hello world" << std::endl;
int v = fib(5);
std::cout << v << std::endl;
emscripten_run_script("alert('I have been called from C!')");
return 0;
}
}