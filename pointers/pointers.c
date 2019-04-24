#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copy over the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/

// *p -> value stored in the memory address
// p -> memory address
// p[] -> value stored in the GIVEN memory address
// p[#] == *(p + #)

// so if you want the next address...
// p++;
// if you want the value in the next address...
// p++;
// *p;
// or
// *(p+1)

void string_copy(char *x, char *y)
{
    // char *x;
    // char *y; not necessary to declare this as an array, or a char, or anything, it's already an array
    int i = 0;
    while (y[i] != '\0')
    {
        printf("%c", *y);
        x[i] = y[i];
        i++;
        y++;
        // this will end the while loop with i being in the last position
    }

    // char *x = '\0';
    x[i] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    // what do i even need to do???
    // i need to find a character c inside str
    int i = 0;
    while (str[i] != '\0')
    {
        if (c == str[i])
        {
            return &str[i];
            // i must research the diff between break, return
        }
        i++;
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int i = 0;
    int j;

    while (haystack[i] != '\0')
    {
        j = i;
        while (haystack[j] == needle[j] && needle[j] != '\0' && haystack[j] != '\0')
        {

            j++;
        }
        if (needle[j] == '\0')
        {

            return &haystack[i - 1];
        }
        i++;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    //begin first test
    char *string = "hello, world";
    char empty[20];

    string_copy(empty, string);
    // begin other tests
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
