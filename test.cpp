#include <stdio.h>
#include <Windows.h>

int main(void)
{
    const int trigger = 500; // ms
    int n = 4;
    const int numDots = 4;
    const char prompt[] = "Loading";
    int k = 0;
    while (k < n)
    {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++)
        {
            Sleep(trigger);
            fputc('.', stdout);
            fflush(stdout);
        }
        k++;
    }
}