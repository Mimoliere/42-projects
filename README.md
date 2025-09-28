# 42-projects

Ce dépôt regroupe les projets que je réalise dans le cadre de mon cursus à l’école 42.  

Ce github sera mit à jour progressivement à mesure que j'avance dans le cursus. Il sera amélioré au fil de mes nouvelles connaissances acquises.

Les projets présents ici n'ont aucunement la prétention d'être parfaits. Ce sont les projets d'un étudiant qui progresse constamment jour après jour, les plus anciens auront donc sûrement moins de cohérence et de soin que les récents (à moins que je ne prenne le temps de leur donner un coup de polish).
Je suis fier des progrès que j'ai pu faire depuis le début, et j'ai bien l'intention de continuer à évoluer et à apprendre. J'espère que ce répertoire pourra témoigner de cela.

PS : Je me suis aidé de l'IA dans la création des README.

---

## Sommaire

- [Organisation du dépôt](#organisation-du-dépôt)
- [Prérequis & outils](#prérequis--outils)
- [Construire et tester (générique)](#construire-et-tester-générique)
- [Liste des projets](#liste-des-projets)
- [Progression (checklist)](#progression-checklist)
- [Ajouter un nouveau projet](#ajouter-un-nouveau-projet)
- [Notes personnelles](#notes-personnelles)

---

## Organisation du dépôt

Arborescence-type attendue pour chaque projet (exemple pour `libft/`) :

```text
42-projects/
├─ libft/
│  ├─ README.md
│  ├─ Makefile
│  ├─ includes/         # en-têtes .h
│  ├─ srcs/             # sources .c/.cpp
│  ├─ sujet/            # énoncé et ressources du projet
│  ├─ tests/            # tests et/ou scripts de validation (optionnel)
│  └─ assets/           # cartes, maps, fichiers d’exemples… (optionnel)
├─ get_next_line/
├─ ft_printf/
└─ ...
```

Explications :
- Un `README.md` local par projet pour les instructions spécifiques.
- Un `Makefile` par projet avec les cibles classiques (`all`, `clean`, `fclean`, `re`, `bonus` si nécessaire).
- Respect de la Norme 42 (Norminette) pour les projets C.

---

## Prérequis & outils

- Outils de build:
  - `make`
  - `gcc`/`clang` pour C, `c++` pour les modules C++ (standard souvent `-std=c++98`)

---

## Construire et tester (générique)

Pour un projet C/C++ typique:

```bash
# Depuis le dossier du projet (ex: libft/)
make            # construit la cible par défaut
make bonus      # si le projet a des bonus
make clean      # supprime les fichiers objets
make fclean     # supprime binaires + objets
make re         # reconstruit from scratch
norminette      # vérifie la norme
```

Exécution des tests (si présents):

```bash
cd tests
./run_tests.sh  # (exemple) ou commandes décrites dans le README du projet
```

---

## Liste des projets


| Projet              | Dossier               | Description courte                                 | Statut     | Note | Sujet |
|---------------------|-----------------------|-----------------------------------------------------|------------|------|-------|
| Libft               | [libft](./libft/)     | Bibliothèque C personnelle                          | Fini    | 106    | [sujet_libft](./libft/sujet/libft.en.subject.pdf)     |
| get_next_line       | [get_next_line](./get_next_line/) | Lecture ligne à ligne d’un fichier/FD     | À venir    | —    | —     |
| ft_printf           | [ft_printf](./ft_printf/) | Réimplémentation de printf                        | À venir    | —    | —     |
| Born2beroot         | [born2beroot](./born2beroot/) | Administration système et virtualisation       | À venir    | —    | —     |
| push_swap           | [push_swap](./push_swap/) | Tri avec opérations sur piles                   | À venir    | —    | —     |
| so_long             | [so_long](./so_long/) | Petit jeu 2D (MiniLibX)                           | À venir    | —    | —     |
| minitalk            | [minitalk](./minitalk/) | Communication client/serveur via signaux        | À venir    | —    | —     |
| minishell           | [minishell](./minishell/) | Mini interpréteur de commandes                  | À venir    | —    | —     |
| philosophers        | [philosophers](./philosophers/) | Threads, mutex, concurrence                   | À venir    | —    | —     |
| NetPractice         | [netpractice](./netpractice/) | Exercices réseau IP                              | À venir    | —    | —     |
| cub3d               | [cub3d](./cub3d/)     | Raycasting (inspiré de Wolfenstein 3D)             | À venir    | —    | —     |
| miniRT              | [miniRT](./miniRT/)   | Raytracer simple                                    | À venir    | —    | —     |
| CPP Modules         | [cpp_modules](./cpp_modules/) | Modules C++ (OOP, orthodox canonical form)    | À venir    | —    | —     |
| Inception           | [inception](./inception/) | Docker, docker-compose                              | À venir    | —    | —     |
| ft_irc              | [ft_irc](./ft_irc/)   | Serveur IRC                                         | À venir    | —    | —     |
| webserv             | [webserv](./webserv/) | Serveur HTTP                                        | À venir    | —    | —     |
| ft_transcendence    | [ft_transcendence](./ft_transcendence/) | Projet web full-stack                        | À venir    | —    | —     |


---

## Progression (checklist)

- [x] Libft
- [ ] get_next_line
- [ ] ft_printf
- [ ] Born2beroot
- [ ] push_swap
- [ ] so_long
- [ ] minitalk
- [ ] minishell
- [ ] philosophers
- [ ] NetPractice
- [ ] cub3d
- [ ] miniRT
- [ ] CPP Modules
- [ ] Inception
- [ ] ft_irc
- [ ] webserv
- [ ] ft_transcendence

---

## Ajouter un nouveau projet

1) Créer le dossier:
```bash
mkdir -p <nom_du_projet>/{src,include,tests,assets,sujet}
cp -n .gitignore <nom_du_projet>/ 2>/dev/null || true
```

2) Ajouter un `README.md` minimal:
```md
# <nom_du_projet>
Description rapide, dépendances, instructions de build et d’exécution.
```

3) Créer un `Makefile` simple (C, exemple):
```make
NAME := <binaire_ou_lib>
CC   := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
INCS := -I include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
```

4) Mettre à jour la [Liste des projets](#liste-des-projets) et la [Progression](#progression-checklist) ci-dessus.

---

## Notes personnelles

- Documenter les choix techniques et pièges rencontrés pour s’y retrouver plus tard.
- Ajouter des tests et des README pour les anciens projets.
