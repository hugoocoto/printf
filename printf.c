extern int write(unsigned int fd, char *buf, unsigned long count);

#include <stdarg.h>

static int
len(char *str)
{
        int count = 0;
        while (str[count])
                ++count;
        return count;
}

static inline int
putchar(int c)
{
        return write(1, (char *) &c, 1);
}

static inline int
putlong(long d)
{
        long rev_d = 0;
        long n = 0;
        char c;
        while (d)
        {
                rev_d *= 10;
                rev_d += d % 10;
                d /= 10;
        }
        while (rev_d)
        {
                c = '0' + (rev_d % 10);
                n += write(1, &c, 1);
                rev_d /= 10;
        }
        return n;
}

static inline int
putstr(char *s)
{
        return write(1, s, len(s) + 1);
}


int
printf(const char *format, ...)
{
        va_list args;
        va_start(args, format);
        char *c = (char *) format;
        int n = 0;
        int size = 0;
        char tempc;
        char *temps;
        while (*c)
        {
                if (*c != '%')
                {
                        n += putchar(*c);
                        ++c;
                        continue;
                }

                switch (*++c)
                {
                case 'd':
                        size = putlong((long) va_arg(args, int));
                        break;

                case 'c':
                        size = putchar(va_arg(args, int));
                        break;

                case 's':
                        size = putstr(va_arg(args, char *));
                        break;

                default:
                        continue;
                }

                c += size;
                n += size;
        }
        va_end(args);
        return n;
}


int
main()
{
        printf("INT %d + %d = %d\n", 1, 3, 1 + 3);
        printf("STR %s\n", "this is a string");
        printf("CHAR %c + %c = %c\n", '1', '3', '1' + '3');
}
