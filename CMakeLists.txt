cmake_minimum_required(VERSION 3.10)
project(Groupe3_EtudeGrapheDeMarkov C)

# Utiliser le standard C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Créer le dossier data s'il n'existe pas
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/data)

# Ajouter tous les fichiers sources
set(SOURCES
        main.c
        Cell.c
        list_adj.c
        utils.c
        export.c
        stack.c
        tarjan.c
        hasse.c
        matrix.c
        menu.c
)

# Créer l'exécutable
add_executable(Groupe3_EtudeGrapheDeMarkov ${SOURCES})

# Inclure les headers
target_include_directories(Groupe3_EtudeGrapheDeMarkov PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Définir le répertoire de travail à la racine du projet
set_target_properties(Groupe3_EtudeGrapheDeMarkov PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)