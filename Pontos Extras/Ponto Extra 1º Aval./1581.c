#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    unsigned short cases, numPeople;
    char currentName[21], previousName[21];
    bool isEnglish;

    scanf("%hu", &cases);

    while (cases--)
    {
        scanf("%hu", &numPeople);
        scanf(" %s", currentName);
        numPeople--;

        isEnglish = false;
        strcpy(previousName, currentName);

        while (numPeople--)
        {
            if (strcmp(currentName, previousName) != 0 && !isEnglish)
            {
                isEnglish = true;
            }
            else
            {
                strcpy(previousName, currentName);
            }

            scanf(" %s", currentName);
        }

        if (isEnglish)
        {
            printf("ingles\n");
        }
        else
        {
            printf("%s\n", currentName);
        }
    }

    return 0;
}
