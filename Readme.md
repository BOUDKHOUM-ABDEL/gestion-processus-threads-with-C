# Gestion des Processus et Threads en C

Ce dépôt contient des programmes en langage C illustrant la gestion des **processus** et des **threads** sous Unix/Linux. Il est destiné à l'apprentissage des concepts fondamentaux de la programmation système, y compris la **création de processus**, la **programmation multi-thread**, la **synchronisation**, et la **communication inter-processus (IPC)**.

## 🔧 Contenu

- `thread_print.c` — Création de threads avec `pthread`, passage de paramètres via struct, affichage concurrent.
- `pipe_named.c` — Communication via FIFO (pipe nommé) entre deux processus indépendants.
- `fork_exec.c` — Utilisation de `fork()` et `exec()` pour lancer un processus fils.
- `mutex_example.c` — Synchronisation entre threads avec `pthread_mutex`.

## ⚙️ Compilation

Tous les programmes sont écrits en C et peuvent être compilés avec `gcc`.  
N'oublie pas d'ajouter l'option `-pthread` pour les programmes utilisant des threads.

Exemple :

```bash
gcc -o thread_print thread_print.c -pthread
▶️ Exécution
bash
Copy
Edit
./thread_print
Pour les programmes utilisant des pipes nommés, assure-toi de créer le pipe dans le terminal avant d’exécuter :

bash
Copy
Edit
mkfifo mypipe
📚 Objectifs pédagogiques
Comprendre la différence entre processus et threads.

Manipuler pthread_create, pthread_join, fork, exec, mkfifo, read, write, etc.

Apprendre à synchroniser des threads (mutex, sémaphores...).

Utiliser des mécanismes de communication inter-processus.

📁 Organisation
Copy
Edit
gestion-processus-threads/
│
├── thread_print.c
├── pipe_named.c
├── fork_exec.c
├── mutex_example.c
└── README.md
📌 À venir
Exemples avec sémaphores (sem_t)

Producteur-consommateur avec FIFO

Threads avec variables partagées et mutex

🌍 English Version (Summary)
This repository showcases how to manage processes and threads in C on Unix/Linux. It includes examples of process creation, threading with pthread, synchronization, and IPC using pipes. Ideal for learning systems programming basics.

🧑‍💻 Auteur
Créé par [TonNom] – étudiant passionné par la programmation système en C.