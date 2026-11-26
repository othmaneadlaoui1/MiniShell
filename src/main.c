#include <stdio.h>   // bach nesta3mlo printf, fgets, putchar, perror
#include <string.h>  // bach nesta3mlo strcmp w strcspn
#include <unistd.h>  // bach nesta3mlo getcwd
#include <sys/types.h> // fih no3 dyal user ID
#include <pwd.h>       // fih struct passwd w getpwuid

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
        
} else if (strcmp(commande, "whoami") == 0) {
    // getuid katjib ra9m dyal user li khddam daba
    // getpwuid katl9a ma3loumat dyal had user f Linux
    struct passwd *utilisateur = getpwuid(getuid());

    // ila l9a user, pw_name fih smiyto
    if (utilisateur != NULL) {
        printf("%s\n", utilisateur->pw_name);
    } else {
        // ila ma l9ahch, perror katbayan sabab l'erreur
        perror("whoami");
    }
        // ila lcommande katbda b "cd "
        } else if (strncmp(commande, "cd ", 3) == 0) {
            // commande + 3 katkhlli pointer ybda mora "cd "
            char *chemin = commande + 3;

            // chdir katbeddel dossier courant
            // katrje3 0 ila nj7at, w -1 ila wa9e3 error
            if (chdir(chemin) == -1) {
                perror("cd");
            }
} 
        else if (strcmp(commande, "exit") != 0 &&
                 commande[0] != '\0') {
            printf("Commande mazal mazednaha: %s\n", commande);
        }

    } while (strcmp(commande, "exit") != 0);

    return 0;  
}
