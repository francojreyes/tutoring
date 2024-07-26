#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void htSet(char *ht[], char *key, char *value);
char *htGet(char *ht[], char *key);
static int hash(char *key);

static char **tokenize(char *s, int *ntokens);
static void freeTokens(char **tokens);

int main(void) {
    char *ht[N] = {};

    char cmd[N] = {};
    while (1) {
        printf("Enter command: ");
        if (!fgets(cmd, N, stdin)) break;

        int ntokens = 0;
        char **tokens = tokenize(cmd, &ntokens);
        if (ntokens < 1) {
            freeTokens(tokens);
            break;
        }

        char cmdName = tokens[0][0];
        char *key = tokens[1];
        char *value;
        switch (cmdName) {
            case 's': // Set ht[key] = value
                if (ntokens != 3) {
                    printf("  Usage: s <key> <value>\n");
                }

                value = tokens[2];
                htSet(ht, key, value);
                printf("  Successfully set ht[\"%s\"] = \"%s\"\n", key, value);
                break;
            case 'g': // Print ht[key]
                if (ntokens != 2) {
                    printf("  Usage: g <key>\n");
                }

                value = htGet(ht, key);
                printf("  ht[\"%s\"] = \"%s\"\n", key, value);
                break;
            case 'h': // Print hash(key)
                if (ntokens != 2) {
                    printf("  Usage: h <key>\n");
                }

                printf("  hash(\"%s\") = %d\n", key, hash(key));
                break;
        }

        freeTokens(tokens);
    }

    for (int i = 0; i < N; i++) {
        free(ht[i]);
    }
}

////////////////////////////////////////////////////////////////////////

char *htGet(char *ht[], char *key) {
	int idx = hash(key);
    return ht[idx];
}

void htSet(char *ht[], char *key, char *value) {
    int idx = hash(key);
	free(ht[idx]);
	ht[idx] = strdup(value);
}

int hash(char *key) {
    int h = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		h = h * 128 + key[i];
	}
	return h % N;
}

////////////////////////////////////////////////////////////////////////

static char **tokenize(char *s, int *ntokens) {
    char *separators = " \t\r\n";
    *ntokens = 0;

    char **tokens = calloc((strlen(s) + 1), sizeof(*tokens));

    while (*s != '\0') {
        s += strspn(s, separators);

        if (*s == '\0') {
            break;
        }

        size_t length = strcspn(s, separators);

        char *token = strndup(s, length);
        s += length;

        tokens[*ntokens] = token;
        (*ntokens)++;
    }

    tokens[*ntokens] = NULL;

    tokens = realloc(tokens, (*ntokens + 1) * sizeof(*tokens));

    return tokens;
}

static void freeTokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}