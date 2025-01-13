extern int write(unsigned int fd, char *buf, unsigned long count);

#include <stdarg.h>

int
putchar(char c)
{
        return write(1, &c, 1);
}

int
putint(int d)
{
        int rev_d = 0;
        int n = 0;
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

int
printf(const char *format, ...)
{
        va_list args;
        va_start(args, format);
        char *c = (char *) format;
        int n = 0;
        int temp = 0;
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
                        temp = putint(va_arg(args, int));
                        c += temp;
                        n += temp;
                        break;
                }
        }
        va_end(args);
        return n;
}


int
main()
{
        printf("%d + %d = %d", 1, 3, 1 + 3);
}
