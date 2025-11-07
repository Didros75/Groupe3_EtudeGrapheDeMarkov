cmake_minimum_required(VERSION 3.10)
project(Groupe3_EtudeGrapheDeMarkov C)

# Utiliser le standard C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Ajouter tous les fichiers sources
set(SOURCES
        main.c
        Cell.c
        list_adj.c
        utils.c
        export.c
)

# Créer l'exécutable
add_executable(Groupe3_EtudeGrapheDeMarkov ${SOURCES})

# Inclure les headers
target_include_directories(Groupe3_EtudeGrapheDeMarkov PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

