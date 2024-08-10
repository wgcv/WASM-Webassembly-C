// emcc memory2.c -o memory2.html -s EXPORTED_FUNCTIONS='["_addOne", "_malloc", "_free"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap", "getValue", "setValue"]'

void addOne(int *input_ptr, int *output_ptr, int len)
{
    int i;
    for (i = 0; i < len; i++)
        output_ptr[i] = input_ptr[i] + 1;
}