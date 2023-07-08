int match(char c1, char c2)
{
    int ASCIIDiference = (int)c1 - (int)c2;
    if (ASCIIDiference == 32 || ASCIIDiference == -32)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *longestNiceSubstring(char *s)
{
    char *ns = (char *)malloc(sizeof(s));

    int start = 0;
    int end = 0;
    int has = 0;

    for (int i = 0; s[i + 1] != '\0'; i++)
    {
        for (int j = i + 1; s[j] != '\0'; j++)
        {
            if (match(s[i], s[j]))
            {
                start = i;
                end = j;
            }
            else
            {
                // start = i;
                // end = j;
            }
        }
    }

    s[end + 1] = '\0';
    return &s[start];
}
