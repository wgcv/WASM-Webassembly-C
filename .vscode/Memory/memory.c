// emcc memory.c -o index.html -s EXPORTED_FUNCTIONS='["_addOne", "_malloc", "_free"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap", "getValue", "setValue"]'

// add one to the value in the input ptr and write this to the content of the output ptr
void addOne(int *input_ptr, int *output_ptr)
{
    *output_ptr = (*input_ptr) + 1;
}