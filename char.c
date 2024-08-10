// emcc char.c -o index.html -s EXPORTED_FUNCTIONS='["_countOccurrences", "_malloc", "_free"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap", "getValue", "setValue"]'

int countOccurrences(char *str, int len, char target)
{
    int i, count = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == target)
        {
            count++;
        }
    }
    return count;
}