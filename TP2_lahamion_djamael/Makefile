CXX = g++
CXXFLAGS = -Wall -std=c++17

# Liste des fichiers source
SRC = main.cpp \
      Vehicule.cpp \
      Voiture.cpp \
      Bateau.cpp \
      VoitureAmphibie.cpp
      
# Générer les fichiers objets
OBJ = $(SRC:.cpp=.o)

# Nom de l'exécutable
EXEC = TP2

# Règle par défaut
all: $(EXEC)

# Édition des liens
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Nettoyage des .o et de l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)
