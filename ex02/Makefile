#Programa
NAME = programa

#Compildar
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

#Diretorios
INC_DIR = include
OBJ_DIR = obj
SRC_DIR = src

#Objetos
OBJ = $(OBJ_DIR)/Account.o $(OBJ_DIR)/tests.o

#Regra padrão
all: $(NAME)

#Executavel
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

#Gerar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#Criar pasta obj
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#Limpar
clean:
	rm -rf $(OBJ_DIR)

#Limpar tudo
fclean: clean
	rm -f $(NAME)

#Recompilar
re: fclean all

# Indicar que estas regras nao sao ficheiros
.PHONY: all clean fclean re