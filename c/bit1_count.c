#include <stdio.h>

int get_char_bit1_num(unsigned char c)
{
    int i,cnt = 0;
    for (i = 0;i < 8;++i)
    {
        if (c & (1 << i))
            cnt++;
    }
    return cnt;
}

int get_char_bit1_num2(unsigned char c)
{
    int i,cnt = 0;
    for (i = 0;i < 8;++i)
    {
        if ((c >> i) & 1)
            cnt++;
    }
    return cnt;
}

int main()
{
    unsigned char c = 0xfe;
    int cnt = 0;
    cnt = get_char_bit1_num(c);
    printf("%d has %d bit 1\n", c, cnt);

    cnt = get_char_bit1_num2(c);
    printf("%d has %d bit 1\n", c, cnt);

    return 0;
}


