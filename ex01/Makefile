NAME = phonebook


#Diretorios
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

#Ficheiros objetos
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/PhoneBook.o $(OBJ_DIR)/Contact.o



#Compildaro
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)


#Regra padrao
all: $(NAME)

#Gerar o executavel
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

#Compilar os objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Limpar ficheiros objetos
clean:
	rm -rf $(OBJ_DIR)

# Limpar tudo: objetos
fclean: clean
	rm -f $(NAME) $(LIB)

# Recompilar tudo
re: fclean all

# Indicar que estas regras nao sao ficheiros
.PHONY: all clean fclean re