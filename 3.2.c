#include <stdio.h>


void escape(char s[], char t[]);

int main() {
    char s[50];
    char t[50] = "hello\tworld\t!\tI\nam\nalright  ";
    escape(s, t);
    printf("%s\n", t);
    printf("%s\n", s);
}

void escape(char s[], char t[]) {
    int s_index = 0;
    int t_index = 0;
    while (t[t_index] != '\0') {
        switch (t[t_index]) {
        case ('\n'):
            s[s_index] = '\\';
            s[s_index + 1] = 'n';
            t_index++;
            s_index = s_index + 2;
            break;
        case ('\t'):
            s[s_index] = '\\';
            s[s_index + 1] = 't';
            t_index++;
            s_index = s_index + 2;
            break;
        default:
            s[s_index] = t[t_index];
            s_index++;
            t_index++;
            break;
        }
    }
    s[s_index] = '\0';
}

