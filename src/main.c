#include <stdio.h>   // bach nesta3mlo printf, fgets, putchar, perror
#include <string.h>  // bach nesta3mlo strcmp w strcspn
#include <unistd.h>  // bach nesta3mlo getcwd

int main(void)
{
    char commande[100];  // blasa fin ghadi nkhznou commande li kteb user
    char dossier[4096];  // blasa fin getcwd ghadi y7et chemin courant

    do {  // bdina boucle: had lcode ghadi y3awed ykhdem
        printf("minishell$ ");  // biyan prompt bach user ykteb
        fflush(stdout);  // khlli prompt yban daba f Terminal

        // qra star li kteb user; ila ma kayn input, dakhl l if
        if (fgets(commande, sizeof commande, stdin) == NULL) {
            putchar('\n');  // sir lstar jdid
            break;          // khrej men boucle
        }

        // 7yed newline li katzidha fgets f akhir lcommande
        commande[strcspn(commande, "\n")] = '\0';

        // wach lcommande hiya pwd?
        if (strcmp(commande, "positionM") == 0) {
            // jib chemin courant w 7etto f dossier
            if (getcwd(dossier, sizeof dossier) != NULL) {
                printf("%s\n", dossier);  // affichi chemin
            } else {
                perror("pwd");  // affichi error ila getcwd ma khdematch
            }
        }
        // ila ma hiyach exit w ma khawiyach, rah commande mazal ma zednaha
        else if (strcmp(commande, "exit") != 0 &&
                 commande[0] != '\0') {
            printf("Commande mazal ma mdfou3ach: %s\n", commande);
        }

    // 3awed boucle ila commande mazal ma hiyach exit
    } while (strcmp(commande, "exit") != 0);

    return 0;  // programme sala b naja7
}
