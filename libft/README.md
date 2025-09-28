# Libft

## 📋 Table des matières

- [À propos](#à-propos)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Fonctions implémentées](#fonctions-implémentées)
  - [Fonctions libc](#fonctions-libc)
  - [Fonctions supplémentaires](#fonctions-supplémentaires)
  - [Fonctions bonus (listes chaînées)](#fonctions-bonus-listes-chaînées)
  - [Printf](#printf)
  - [Get Next Line](#get-next-line)
- [Structure du projet](#structure-du-projet)
- [Compilation](#compilation)

## À propos

Libft est une bibliothèque C personnalisée implémentant des fonctions de la libc standard ainsi que des fonctions utilitaires supplémentaires.
Cette bibliothèque est sensée être notre boîte à outils personnelle pour les futurs projets en C du cursus et devrait être développée au fur et à mesure de notre avancée.

C'était un projet assez rapide et facile à faire, de quoi se remettre dans le bain pour le début du cursus.

## Installation

```bash
git clone [votre-repo]
cd libft
make
```

## Utilisation

1. Compilez la bibliothèque avec `make`
2. Incluez le fichier d'en-tête dans vos fichiers C :
```c
#include "includes/libft.h"
```
3. Compilez votre projet avec la bibliothèque :
```bash
gcc -Wall -Wextra -Werror -o mon_programme mon_fichier.c -L emplacement_libft -lft
```

## Fonctions implémentées

### Fonctions libc

#### Fonctions de vérification de caractères
- `ft_isalpha` - Vérifie si le caractère est alphabétique
- `ft_isdigit` - Vérifie si le caractère est un chiffre
- `ft_isalnum` - Vérifie si le caractère est alphanumérique
- `ft_isascii` - Vérifie si le caractère est ASCII
- `ft_isprint` - Vérifie si le caractère est imprimable

#### Fonctions de manipulation de chaînes
- `ft_strlen` - Calcule la longueur d'une chaîne
- `ft_strchr` - Cherche un caractère dans une chaîne
- `custom_strchr` - Version personnalisée de strchr
- `ft_strrchr` - Cherche un caractère dans une chaîne (depuis la fin)
- `ft_strncmp` - Compare deux chaînes sur n caractères
- `ft_strlcpy` - Copie une chaîne avec limitation de taille
- `ft_strlcat` - Concatène des chaînes avec limitation de taille
- `ft_strnstr` - Cherche une sous-chaîne dans une chaîne

#### Fonctions de manipulation de mémoire
- `ft_memset` - Remplit la mémoire avec un octet
- `ft_bzero` - Met à zéro une zone mémoire
- `ft_memcpy` - Copie une zone mémoire
- `ft_memmove` - Copie une zone mémoire (gère les chevauchements)
- `ft_memchr` - Cherche un octet dans la mémoire
- `ft_memcmp` - Compare deux zones mémoire

#### Fonctions de conversion
- `ft_atoi` - Convertit une chaîne en entier
- `ft_toupper` - Convertit en majuscule
- `ft_tolower` - Convertit en minuscule

#### Fonctions d'allocation
- `ft_calloc` - Alloue et initialise la mémoire
- `custom_calloc` - Version personnalisée de calloc avec valeur d'initialisation
- `ft_strdup` - Duplique une chaîne

### Fonctions supplémentaires

#### Manipulation de chaînes avancée
- `ft_substr` - Extrait une sous-chaîne
- `ft_strjoin` - Joint deux chaînes
- `altered_ft_strjoin` - Version modifiée de strjoin (libère s1)
- `ft_strtrim` - Supprime les caractères indésirables
- `ft_split` - Divise une chaîne selon un délimiteur
- `ft_cpytillsep` - Copie une chaîne jusqu'à un séparateur
- `ft_strmapi` - Applique une fonction à chaque caractère
- `ft_striteri` - Itère sur une chaîne avec une fonction

#### Conversion et utilitaires
- `ft_itoa` - Convertit un entier en chaîne

#### Fonctions de sortie
- `ft_putchar_fd` - Écrit un caractère sur un descripteur de fichier
- `ft_putstr_fd` - Écrit une chaîne sur un descripteur de fichier
- `ft_putendl_fd` - Écrit une chaîne suivie d'un retour à la ligne
- `ft_putnbr_fd` - Écrit un nombre sur un descripteur de fichier
- `ft_putnbrbase_fd` - Écrit un nombre dans une base donnée

#### Fonctions pour printf (comptage de caractères)
- `ft_putchar_counts` - Écrit un caractère et compte
- `ft_putstr_counts` - Écrit une chaîne et compte les caractères
- `ft_putnbr_counts` - Écrit un nombre et compte les caractères
- `ft_putnbrbase_counts` - Écrit un nombre en base et compte les caractères

### Fonctions bonus (listes chaînées)

- `ft_lstnew` - Crée un nouveau nœud
- `ft_lstadd_front` - Ajoute un nœud au début
- `ft_lstadd_back` - Ajoute un nœud à la fin
- `ft_lstsize` - Compte les nœuds
- `ft_lstlast` - Retourne le dernier nœud
- `ft_lstdelone` - Supprime un nœud
- `ft_lstclear` - Supprime et libère tous les nœuds
- `ft_lstiter` - Itère sur la liste
- `ft_lstmap` - Applique une fonction et crée une nouvelle liste

### Printf

Une implémentation personnalisée de `printf` avec support des conversions :
- `%c` - caractère
- `%s` - chaîne
- `%d`, `%i` - entier décimal
- `%u` - entier non signé
- `%x`, `%X` - hexadécimal
- `%p` - pointeur
- `%%` - caractère %

### Get Next Line

- `get_next_line` - Lit une ligne depuis un descripteur de fichier
- Buffer configurable via `BUFFER_SIZE`

### Fonctions utilitaires supplémentaires

- `ft_strcmp` - Compare deux chaînes complètes
- `ft_has_char` - Vérifie si une chaîne contient un caractère
- `ft_strndup` - Duplique n caractères d'une chaîne
- `free_arr` - Libère un tableau de chaînes
- `ft_countwords` - Compte les mots dans une chaîne
- `ft_max` - Retourne le maximum entre deux entiers
- `ft_min` - Retourne le minimum entre deux entiers
- `ft_atoll` - Convertit une chaîne en long long
- `is_allchar` - Vérifie si tous les caractères d'une chaîne sont identiques à un caractère donné
- Fonctions étendues de vérification (`ft_isalldigit`, `ft_isallalpha`, `ft_isallalnum`... etc)

## Structure du projet

```
libft/
├── Makefile                # Fichier de compilation
├── README.md               # Ce fichier
├── includes/
│   └── libft.h             # Fichier d'en-tête principal
└── srcs/                   # Fichiers sources
    ├── ft_*.c              # Fonctions principales
    ├── *_bonus.c           # Fonctions bonus
    ├── ft_printf*.c        # Implémentation printf
    └── get_next_line.c     # Implémentation GNL
```

## Compilation

### Commandes make disponibles

- `make` ou `make all` - Compile la bibliothèque de base
- `make bonus` - Compile avec les fonctions bonus
- `make clean` - Supprime les fichiers objets
- `make fclean` - Supprime les fichiers objets et la bibliothèque
- `make re` - Recompile entièrement

### Flags de compilation

La bibliothèque est compilée avec les flags suivants :
- `-Wall` - Active tous les avertissements
- `-Wextra` - Active des avertissements supplémentaires  
- `-Werror` - Traite les avertissements comme des erreurs
- `-g3` - Active les informations de débogage

---

**Auteur :** Mimoliere 
**École :** 42
**Date :** Novembre 2024
