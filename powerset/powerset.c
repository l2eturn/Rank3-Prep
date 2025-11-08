/* powerset_lex.c
   วิธี: recursive backtracking
   ผลลัพธ์จะพิมพ์เป็นบรรทัดๆ เช่น:
   { }
   { a }
   { a b }
   { a b c }
   { a c }
   { b }
   { b c }
   { c }
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_subset(char *buf)
{
    /* buf เป็น null-terminated string ของสมาชิก subset ตามลำดับเดิม */
    int first = 1;
    putchar('{');
    putchar(' ');
    for (int i = 0; buf[i]; i++)
    {
        if (!first) putchar(' ');
        putchar(buf[i]);
        first = 0;
    }
    putchar(' ');
    putchar('}');
    putchar('\n');
}

void dfs(char *set, int start, char *buf, int buflen)
{
    /* พิมพ์ subset ปัจจุบันก่อน แล้วขยายด้วยตัวถัดไป (ให้ได้ lexicographic order) */
    print_subset(buf);

    int n = strlen(set);
    for (int i = start; i < n; i++)
    {
        int len = strlen(buf);
        if (len + 1 < buflen) {
            buf[len] = set[i];
            buf[len+1] = '\0';
            dfs(set, i + 1, buf, buflen);
            buf[len] = '\0'; /* backtrack */
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *s = argv[1];
    int n = strlen(s);
    /* buffer สำหรับเก็บ subset ชั่วคราว (ยาวได้ n ตัว + null) */
    char *buf = malloc(n + 1);
    if (!buf) return 1;
    buf[0] = '\0';

    dfs(s, 0, buf, n + 1);

    free(buf);
    return 0;
}
