/*
Programul primeste un text file si un string si afiseaza toate aparitiile
ex "asd*f" -> asd(mai multe caractere)f
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define model_max 1000
#define text_max 10000

void preKmp(char* model,int *k) 
{
    int len_model = strlen(model);
    k[0] = 0;
    int j = 0;
    for (int i = 1; i < len_model; i++)
    {
        while (j > 0 && model[i] != model[j] && model[j]!='?')
            j = k[j - 1];
        if (model[i] == model[j] || model[j] == '?' || model[i] == '?')
            j++;
        k[i] = j;
    }
}

int cauta(char* text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
        if (text[i] == '?')
            return i;
    return -1;
}

//cautare daca avem ? sau niciun wildcard (putem avea mai multe potriviri de model)
void kmp_1(char* text, char* model)
{
    int len_model = strlen(model), len_text = strlen(text);
    int* k = (int*)malloc(sizeof(int) * len_model);
    if (k == NULL)
    {
        printf("Eroare la alocare.");
        exit(-1);
    }
    preKmp(model, k);
    int i = 0, j = 0;
    while (i < len_text)
    {
        if (j < len_model && (model[j] == text[i] || model[j] == '?'))
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
            {
                if (cauta(model) == -1)
                    j = k[j - 1];
                else
                {
                    if (cauta(model) == 0)
                    {
                        j = 1;
                        i++;
                    }
                    else
                        if (cauta(model) < j)
                            j = k[cauta(model) - 1];
                        else
                            j = k[j - 1];
                }
            }
            else
                i++;
        }
        if (j == len_model)
        {
            printf("Gasit de la pozitia %d la pozitia %d: ", i - len_model, i-1);
            for (int x = 0; x < len_model; x++)
                putchar(text[i - len_model + x]);
            printf("\n");
            if (cauta(model) == -1)
                j = k[j - 1];
            else
            {
                if (cauta(model) == 0)
                    j = 1;
                else
                    j = k[cauta(model) - 1];
            }
        }
    }
    free(k);
}

//functie care ajuta la gasirea lui ant
int findAnt(char* model, char ultima)
{
    int len = strlen(model);
    for (int i = 0; i < len; i++)
    {
        if (model[i] == ultima)
            return i;
    }
    return -1;
}

//functie care ajuta la gasirea lui post
int findPost(char* model, char prima)
{
    int len = strlen(model);
    for (int i = len - 1; i >= 0; i--)
        if (model[i] == prima)
            return i;
    return -1;
}

//se foloseste pentru a afla de cate ori apare * intr-un sir
int aparitii(char* sir, char c)
{
    int len = strlen(sir);
    int ct = 0;
    for (int i = 0; i < len; i++)
        if (sir[i] == c)
            ct++;
    return ct;
}

//returneaza indicele de la care incepe modelul pentru prima data in text
int kmp_start(char* text, char* ant)
{
    int len_model = strlen(ant), len_text = strlen(text);
    int* k = (int*)malloc(sizeof(int) * len_model);
    if (k == NULL)
    {
        printf("Eroare la alocare.");
        exit(-1);
    }
    preKmp(ant, k);
    int i = 0, j = 0;
    while (i < len_text)
    {
        if (j < len_model && (ant[j] == text[i] || ant[j] == '?'))
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
                if (cauta(ant) == -1)
                    j = k[j - 1];
                else
                {
                    if (cauta(ant) == 0)
                    {
                        j = 1;
                        i++;
                    }
                    else
                        if (cauta(ant) < j)
                            j = k[cauta(ant) - 1];
                        else
                            j = k[j - 1];
                }
            else
                i++;
        }
        if (j == len_model)
        {
            return i - len_model;
        }
    }
    return -1;
}


//returneaza indicele de la care incepe subsirul in sir ultima data
int kmp_end(char* text, char* post)
{
    int len_model = strlen(post), len_text = strlen(text);
    int* k = (int*)malloc(sizeof(int) * len_model);
    if (k == NULL)
    {
        printf("Eroare la alocare.");
        exit(-1);
    }
    preKmp(post, k);
    int i = 0, j = 0, final = -1;
    while (i < len_text)
    {
        if (j < len_model && (post[j] == text[i] || post[j] == '?'))
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
                if (cauta(post) == -1)
                    j = k[j - 1];
                else
                {
                    if (cauta(post) == 0)
                    {
                        j = 1;
                        i++;
                    }
                    else
                        if (cauta(post) < j)
                            j = k[cauta(post) - 1];
                        else
                            j = k[j - 1];
                }
            else
                i++;
        }
        if (j == len_model)
        {
            final = i;
            if (cauta(post) == -1)
                j = k[j - 1];
            else
            {
                if (cauta(post) == 0)
                    j = 1;
                else
                    j = k[cauta(post) - 1];
            }
        }
    }
    return final;
}

//cautare daca avem *
void kmp_2(char* text,char* model) {
    int len_model = strlen(model), len_text = strlen(text);
    int ap = aparitii(model, '*');
    if (ap == 0)
    {
        kmp_1(text, model);
        return;
    }
    //ant - sirul de dinaintea primei *; post - sirul de dupa ultima *
    //start - indicele de la care incepe modelul in text
    //end - indicele la care se sfarseste modelul in text avand in interior numarul maxim de caractere
    char ant[model_max], post[model_max];
    int start, end;
        strcpy(ant, model);
        if (findAnt(model, '*') == 0)
            start = 0;    //avem * pe prima pozitie in model
        else
        {
            ant[findAnt(model, '*')] = '\0';
            start = kmp_start(text, ant);
        }
        if (model[strlen(model)-1]=='*')
            end = len_text;
        else
        {
            strcpy(post, model + findPost(model, '*') + 1);
            end = kmp_end(text, post);
        }
        if (start == -1 || end == -1)
        {
            printf("Nu s-a gasit sirul\n");
            return;
        }
        if (aparitii(model, '*') != 1)
        {
            strcpy(model, model + findAnt(model, '*') + 1);
            if (findPost(model, '*') != -1)
                model[findPost(model, '*')] = '\0';
            else
                strcpy(model, "");
            while (model && aparitii(model, '*'))
            {
                if (aparitii(model, '*') == 2)
                {
                    strcpy(model, model + findAnt(model, '*') + 1);
                    model[findPost(model, '*')] = '\0';
                    if (kmp_start(text, model) == -1)
                    {
                        printf("Nu s-a gasit sirul\n");
                        return;
                    }
                }
                char ant_aux[model_max], post_aux[model_max];
                strcpy(ant_aux, model);
                ant_aux[findAnt(model, '*')] = '\0';
                strcpy(post_aux, model + findPost(model, '*') + 1);
                int a = kmp_start(text, ant_aux), b = kmp_end(text, post_aux);
                if (a == -1 || b == -1)
                {
                    printf("Nu s-a gasit sirul\n");
                    return;
                }
                strcpy(model, model + findAnt(model, '*') + 1);
                if (findPost(model, '*') != -1)
                    model[findPost(model, '*')] = '\0';
                else
                    strcpy(model, "");
            }
        }
        printf("Gasit de la pozitia %d la pozitia %d: ", start, end - 1);
        for (int i = start; i < end; i++)
            putchar(text[i]);
        printf("\n");
}

int main(void)
{
	FILE* f = fopen("Text.txt", "r");
	if (f == NULL)
	{
		printf("Eroare deschidere fisier.");
		exit(-1);
	}
	char text[text_max];
	int len_text = fread(text, sizeof(char), text_max - 1, f);
    text[len_text] = '\0';
	fclose(f);
    char model1[model_max] = "bmn?";
    char model2[model_max] = "yr?y";
    char model3[model_max] = "?ryu";
    char model4[model_max] = "*truy*";
    char model5[model_max] = "b?b*ry";
    char model6[model_max] = "mn*bn*b";
    char model7[model_max] = "mn*bn*";
    kmp_2(text, model1);
    kmp_2(text, model2);
    kmp_2(text, model3);
    kmp_2(text, model4);
    kmp_2(text, model5);
    kmp_2(text, model6);
    kmp_2(text, model7);
    return 0;
}