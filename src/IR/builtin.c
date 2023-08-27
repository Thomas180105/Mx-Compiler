// enable bool type
#define bool _Bool

// libc function
int printf(const char *pattern, ...);
int sprintf(char *dest, const char *pattern, ...);
int scanf(const char *pattern, ...);
int sscanf(const char *src, const char *pattern, ...);
unsigned strlen(const char *str);
int strcmp(const char *s1, const char *s2);
void *memcpy(void *dest, const void *src, unsigned n);
void *malloc(unsigned n);

//enable other function
void print(char *str) {printf("%s", str);}
void println(char *str) {printf("%s\n", str);}
void printInt(int n) {printf("%d", n);}
void printlnInt(int n) {printf("%d\n", n);}
char *getString()
{
    char *buffer = malloc(4096);
    scanf("%s", buffer);
    return buffer;
}
int getInt()
{
    int n;
    scanf("%d", &n);
    return n;
}
char *toString(int n)
{
    char *buffer = malloc(16);
    sprintf(buffer, "%d", n);
    return buffer;
}
int array_size(void *this_) {return ((int*)this_)[-1];}
unsigned string_length(char *this_) {return strlen(this_);}
char *string_substring(char *this_, int left, int right)
{
    int length = right - left;
    char *buffer = malloc(length + 1);
    memcpy(buffer, this_ + left, length);
    buffer[length] = '\0';
    return buffer;
}
int string_parseInt(char *this_)
{
    int n;
    sscanf(this_, "%d", &n);
    return n;
}
int string_ord(char *this_, int pos) {return this_[pos];}
char *string_add(char *str1, char *str2)
{
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    int length = length1 + length2;
    char *buffer = malloc(length + 1);
    memcpy(buffer, str1, length1);
    memcpy(buffer + length1, str2, length2);
    buffer[length] = '\0';
    return buffer;
}
bool string_equal(char *str1, char *str2) {return strcmp(str1, str2) == 0;}
bool string_notEqual(char *str1, char *str2) {return strcmp(str1, str2) != 0;}
bool string_less(char *str1, char *str2) {return strcmp(str1, str2) < 0;}
bool string_greater(char *str1, char *str2) {return strcmp(str1, str2) > 0;}
bool string_lessOrEqual(char *str1, char *str2) {return strcmp(str1, str2) <= 0;}
bool string_greaterOrEqual(char *str1, char *str2) {return strcmp(str1, str2) >= 0;}
void *__newPtrArray(int size)
{
    int *array = malloc((size << 2) + 4);
    array[0] = size;
    return array + 1;
}
void *__newIntArray(int size)
{
    int *array = malloc((size << 2) + 4);
    array[0] = size;
    return array + 1;
}
void *__newBoolArray(int size)
{
    int *array = malloc(size + 4);
    array[0] = size;
    return array + 1;
}
