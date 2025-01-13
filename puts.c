extern int write(unsigned int fd, char *buf, unsigned long count);

int
len(char *str)
{
        int count = 0;
        while (str[count])
                ++count;
        return count;
}

// put a string into stdout
int
puts(char *buf)
{
        int n = write(1, buf, len(buf)) + write(1, "\n", 1);
        return n;
}

int
main()
{
        puts("Hello world!");
}
