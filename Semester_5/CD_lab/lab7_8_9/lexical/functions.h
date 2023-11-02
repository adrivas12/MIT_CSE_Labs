#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

int ispredefFunc(const char *str)
{
    for (int i = 0; i < sizeof(predefFuncs) / sizeof(char *); i++)
    {
        if (strcmp(str, predefFuncs[i]) == 0)
            return 1;
    }
    return 0;
}

int isKeyword(const char *str)
{
    for (int i = 0; i < sizeof(Keywords) / sizeof(char *); i++)
    {
        if (strcmp(str, Keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isReturnType(const char *str)
{
    for (int i = 0; i < sizeof(ReturnTypes) / sizeof(char *); i++)
    {
        if (strcmp(str, ReturnTypes[i]) == 0)
            return 1;
    }
    return 0;
}

int isDataType(const char *str)
{
    for (int i = 0; i < sizeof(DataTypes) / sizeof(char *); i++)
    {
        if (strcmp(str, DataTypes[i]) == 0)
            return 1;
    }
    return 0;
}
int isbracket(char c)
{ // function to check for bracket
	for (int i = 0; i < 6; i++)
	{
		if (brackets[i] == c)
			return 1;
	}
	return 0;
}
int charBelongsTo(int c, const char *arr)
{
    int len;
    if (arr == specialsymbols)
        len = sizeof(specialsymbols) / sizeof(char);
    else if (arr == arithmeticsymbols)
        len = sizeof(arithmeticsymbols) / sizeof(char);
    for (int i = 0; i < len; i++)
    {
        if (c == arr[i])
            return 1;
    }
    return 0;
}
void newLine()
{
    printf("\n");
    ++row;
    col = 1;
}

#endif