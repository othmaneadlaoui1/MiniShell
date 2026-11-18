# MiniShell

## Présentation

MiniShell est un projet développé en langage C qui consiste à créer un interpréteur de commandes simplifié, inspiré de Bash, sous Linux.

L'objectif est de comprendre le fonctionnement d'un Shell et de maîtriser les principaux mécanismes de programmation système.

## Fonctionnalités

- Lecture et interprétation des commandes.
- Exécution des commandes internes et externes.
- Gestion des processus.
- Redirections et pipes.
- Gestion des variables d'environnement.
- Gestion des signaux et des erreurs.

## Technologies et outils

| Outil | Utilisation |
|---|---|
| C | Langage de programmation |
| Linux | Environnement d'exécution |
| GCC | Compilation |
| Make | Automatisation de la compilation |
| Git | Gestion des versions |
| GitHub | Collaboration et hébergement du code |
| VS Code | Édition du code |

## Installation

Cloner le repository :

```bash
git clone <https://github.com/othmaneadlaoui1/MiniShell.git>
cd minishell
```

Compiler le projet :

```bash
make
```

Lancer le programme :

```bash
./minishell
```

## Structure du projet

```text
minishell/
├── include/
├── src/
│   ├── parsing/
│   ├── execution/
│   ├── builtins/
│   ├── signals/
│   └── utils/
├── Makefile
├── .gitignore
└── README.md
```

## Collaboration

- Créer une branche pour chaque fonctionnalité.
- Respecter l'organisation du projet.
- Tester les modifications avant leur intégration.
- Utiliser des commits clairs et explicites.
- Intégrer les modifications via Pull Request.

## Choix des outils

- **C :** manipulation des processus et programmation système.
- **Linux :** accès aux fonctionnalités Unix.
- **GCC :** compilation du code.
- **Make :** automatisation de la compilation.
- **Git et GitHub :** gestion des versions et travail collaboratif.
- **VS Code :** environnement de développement.

---

*Projet pédagogique — Développement d'un Shell simplifié en C.*