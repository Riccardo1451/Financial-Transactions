cmake_minimum_required(VERSION 3.28)
project(Laboratorio_di_Programmazione)

# Imposta la versione standard di C++ corretta.
set(CMAKE_CXX_STANDARD 20)

# Aggiungi GoogleTest come sottodirectory.
add_subdirectory(googletest)

# Aggiungi i file sorgenti del progetto principale.
set(SOURCE_FILES
        main.cpp
        Transazione.h
        Transazione.cpp
        ContoCorrente.cpp
        ContoCorrente.h
        FileManager.cpp
        FileManager.h
        ObjectNotFound.h
        ObjectNotReady.h
)

# Aggiungi i file sorgenti dei test.
set(TEST_FILES
        test/test_Transazione.cpp
        test/test_ContoCorrente.cpp
        test/test_FileManager.cpp
)

# Crea l'eseguibile del progetto principale.
add_executable(MainExecutable ${SOURCE_FILES})

# Crea l'eseguibile dei test.
add_executable(run_tests
        Transazione.h
        Transazione.cpp
        ContoCorrente.cpp
        ContoCorrente.h
        FileManager.cpp
        FileManager.h
        ${TEST_FILES})

# Collega le librerie di GoogleTest solo all'eseguibile dei test.
target_link_libraries(run_tests gtest gmock gtest_main)

# Abilita la possibilità di eseguire i test con CMake.
enable_testing()

# Aggiungi il test utilizzando l'eseguibile 'run_tests'.
add_test(NAME run_tests COMMAND run_tests)

include_directories(/Users/riccardofantechi/Desktop/Universita/Primo\ anno/Laboratorio\ di\ Programmazione/googletest/googlemock/include)
include_directories(/Users/riccardofantechi/Desktop/Universita/Primo\ anno/Laboratorio\ di\ Programmazione/googletest/googletest/include)


