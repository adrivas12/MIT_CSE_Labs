#ifndef __HASH_H__
#define __HASH_H__

struct ListElement *ST[MAX_SIZE]; 
void Initialize()
{
	for(int i=0; i<MAX_SIZE; i++)
		ST[i]=NULL; 
}

int hash(char *str)
{
	int sum=0; 
	for(int i=0; i<strlen(str); i++)
		sum+=str[i]; 

	return sum%MAX_SIZE; 
}

void display_ST()		//display Symbol Table
{
	printf("Index\tLex Name\tReturn Type\t Data type\tToken type\tNo of arguments\n"); 
	for(int i=0; i<MAX_SIZE; i++)
	{
		if(ST[i]==NULL)
			continue; 
		else 
		{
			struct ListElement *cur=ST[i]; 
			while(cur)
			{
				printf("%d\t%s\t%s\t%s\t%s\t%d\n", cur->index, cur->lexeme, cur->return_type, cur->data_type, cur->token_type, cur->argc); 
				cur=cur->next; 
			}
		}
	}
}

int search_ST(char identifier[])		//Search in Symbol Table 
{
	int index=hash(identifier); 
	if(ST[index]==NULL)
		return -1; 
	struct ListElement *cur = ST[index]; 
	int i=0; 

	while(cur!=NULL)
	{
		if(strcmp(identifier, cur->name)==0)
			return i; 
		cur=cur->next; 
		i++; 
	}
	return -1; 
}

void insert(struct token tk)
{
	if(search_ST(identifier)==1)
	{
		return; 
	}
	int val=hash(tk.lexeme); 
	struct ListElement *n=(struct ListElement *)malloc(sizeof(struct ListElement)); 
	n->tkn=tk; 
	n->next=NULL; 
	if(ST[val]==NULL)
		ST[val]=n; 
	else 
	{
		struct ListElement *ele=ST[val]; 
		while(ele->next!=NULL)
		{
			ele=ele->next; 
		}
		ele->next=cur; 
	}
}
void fillToken(struct token *tkn, char c, int row, int col, char *type)
{
    tkn->row = row;
    tkn->col = col;
    strcpy(tkn->type, type);
    tkn->lexeme[0] = c;
    tkn->lexeme[1] = '\0';
}
struct token getNextToken(FILE *fin)
{
    int c;
    struct token tkn = {.row = -1};
    int gotToken = 0;
    while (!gotToken && (c = fgetc(fin)) != EOF)
    {
        if (c == '/')
        {
            int d = fgetc(fin);
            ++col;
            if (d == '/')
            {
                while ((c = fgetc(fin)) != EOF && c != '\n')
                    ++col;
                if (c == '\n')
                    newLine();
            }
            else if (d == '*')
            {
                do
                {
                    if (d == '\n')
                        newLine();
                    while ((c = fgetc(fin)) != EOF && c != '*')
                    {
                        ++col;
                        if (c == '\n')
                            newLine();
                    }
                    ++col;
                } while ((d = fgetc(fin)) != EOF && d != '/' && (++col));
                ++col;
            }
            else
            {
                fillToken(&tkn, c, row, --col, "/");
                gotToken = 1;
                fseek(fin, -1, SEEK_CUR);
            }
        }
        else if (charBelongsTo(c, specialsymbols))
        {
            char symbol[2] = {c, '\0'};
            fillToken(&tkn, c, row, col, symbol);
            gotToken = 1;
            ++col;
        }
        else if (charBelongsTo(c, arithmeticsymbols))
        {
            char symbol[2] = {c, '\0'};
            fillToken(&tkn, c, row, col, symbol);
            gotToken = 1;
            ++col;
        }
        else if (isbracket(c))
        {
            char symbol[2] = {c, '\0'};
            fillToken(&tkn, c, row, col, symbol);
            gotToken = 1;
            ++col;
        }
        else if (c == '+' || c == '-')
        {
            int d = fgetc(fin);
            if (d != c)
            {
                char symbol[2] = {c, '\0'};
                fillToken(&tkn, c, row, col, symbol);
                gotToken = 1;
                ++col;
                fseek(fin, -1, SEEK_CUR);
            }
            else
            {
                char symbol[3] = {c, c, '\0'};
                fillToken(&tkn, c, row, col, symbol);
                gotToken = 1;
                col += 2;
            }
        }
        else if (c == '=' || c == '<' || c == '>')
        {
            char symbol[2] = {c, '\0'};
            fillToken(&tkn, c, row, col, symbol);
            gotToken = 1;
            ++col;
            int d = fgetc(fin);
            if (d == '=')
            {
                ++col;
                strcat(tkn.lexeme, "=");
            }
            else
            {
                fseek(fin, -1, SEEK_CUR);
            }
        }
        else if (isdigit(c))
        {
            tkn.row = row;
            tkn.col = col++;
            tkn.lexeme[0] = c;
            int k = 1;
            while ((c = fgetc(fin)) != EOF && isdigit(c))
            {
                tkn.lexeme[k++] = c;
                col++;
            }
            tkn.lexeme[k] = '\0';
            strcpy(tkn.type, "Number");
            gotToken = 1;
            fseek(fin, -1, SEEK_CUR);
        }
        else if (c == '#')
        {
            while ((c = fgetc(fin)) != EOF && c != '\n');
            newLine();
        }
        else if (c == '\n')
        {
            newLine();
            c = fgetc(fin);
            if (c == '#')
            {
                while ((c = fgetc(fin)) != EOF && c != '\n')
                    ;
                newLine();
            }
            else if (c != EOF)
                fseek(fin, -1, SEEK_CUR);
        }
        else if (isspace(c))
            ++col;
        else if (isalpha(c) || c == '_')
        {
            tkn.row = row;
            tkn.col = col++;
            tkn.lexeme[0] = c;
            int k = 1;
            while ((c = fgetc(fin)) != EOF && isalnum(c))
            {
                tkn.lexeme[k++] = c;
                ++col;
            }
            tkn.lexeme[k] = '\0';
            if (isKeyword(tkn.lexeme))
                strcpy(tkn.type, "Keyword");
            else
                strcpy(tkn.type, "Identifier");
            gotToken = 1;
            fseek(fin, -1, SEEK_CUR);
        }
        else if (c == '"')
        {
            tkn.row = row;
            tkn.col = col;
            strcpy(tkn.type, "StringLiteral");
            int k = 1;
            tkn.lexeme[0] = '"';
            while ((c = fgetc(fin)) != EOF && c != '"')
            {
                tkn.lexeme[k++] = c;
                ++col;
            }
            tkn.lexeme[k] = '"';
            gotToken = 1;
        }
        else if (c == '&' || c == '|')
        {
            int d = fgetc(fin);
            if (d == c)
            {
                tkn.lexeme[0] = tkn.lexeme[1] = c;
                tkn.lexeme[2] = '\0';
                tkn.row = row;
                tkn.col = col;
                ++col;
                gotToken = 1;
                char symbol[3] = {c, c, '\0'};
                fillToken(&tkn, c, row, col, symbol);
            }
            else
                fseek(fin, -1, SEEK_CUR);
            ++col;
        }
        else
            ++col;
    }
    return tkn;
}
void printToken(struct token *tkn, int *index)
{
	if(strcmp(tkn->type, "Identifier")==0)
	{
		char id[10]; 
		if(search(tkn->lexeme)==0)
		{
			tkn->index=*index; 
			(*index)++; 
		}
		else
		{
			struct ListElement *cur=ST[hash(tkn->lexeme)]; 
			while(cur)
			{
				if(strcmp(cur->tkn.lexeme, tkn->lexeme)==0)
				{
					tkn->index=cur->tkn.index;
					break; 
				}
				cur=cur->next; 
			}
		}
		sprintf(id, "id%d", tkn->index); 
		printf("<%s, %d, %d>", id, tkn->row, tkn->col); 
		return; 
	}
	printf("<%s, %d, %d>", tkn->lexeme, tkn->row, tkn->col); 
}
void insert_ST(struct token tkn, char *type, char *recTypekn, int argc)
{
	if(strcmp(tkn.type, "Identifier")==0)
	{
		if(strcmp(type, "VAR")==0)
		{
			tkn.argc=0; 
			strcpy(tkn.return_type, "-"); 
			strcpy(tkn.token_type, type); 
			strcpy(tkn.data_type, recTypekn); 
			insert(tkn); 
		}
		else
		{
			tkn.argc=argc; 
			strcpy(tkn.return_type, recTypekn); 
			strcpy(tkn.token_type, type); 
			strcpy(tkn.data_type, "-"); 
			insert(tkn); 
		}
	}
}

#endif