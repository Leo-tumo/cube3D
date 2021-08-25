NAME 			= cube3D
HEADER			= cube3d.h
LIBFT_DIR		= libs/libft/
LIBFT 			= $(LIBFT_DIR)libft.a
LIBMLX_DIR 		= libs/minilibx_mms/
LIBMLX 			= $(LIBMLX_DIR)libmlx.dylib
MAKE 			= make
CLEAN 			= clean
FCLEAN 			= fclean
SRC				= main.c\
				rainbow.c
OBJ 			= $(SRC:.c=.o)
CC				= gcc
FLAG			= -Wall -Werror -Wextra -g -O0
FLAGMLX			= -framework OpenGL -framework AppKit
OPTION 			= -c -D GL_SILENCE_DEPRECATION 
OPTION_OBJ		= -o
DEL				= rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX) $(HEADER)
	@cd $(LIBFT_DIR) && mv ./libft.a ../../
	@cd $(LIBMLX_DIR) && mv ./libmlx.dylib ../../
	@$(CC) $(FLAG) $(OBJ) -L. -lmlx -lft $(FLAGMLX) $(OPTION_OBJ) $(NAME) 
	@tput  setaf 190 && echo "\t📦3D\t\tCREATED"

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)
	@tput bold && tput setaf 933 && echo "\tLIBFT\t\tCREATED"
	@tput setaf 784

$(LIBMLX):
	@cd $(LIBMLX_DIR) && $(MAKE)
	@tput setaf 964 && echo "\tMLX\t\tCREATED"

%.o: %.c
	@$(CC) $(FLAG) $(OPTION) $< $(OPTION_OBJ) $@

.PHONY: all clean fclean re l


l: all
	@./cube3D
	
clean:
	@$(DEL) $(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)
	@cd $(LIBMLX_DIR) && $(MAKE) $(CLEAN)
	@$(DEL) $(OBJ)
	@tput setaf 45 && echo "\tALL\t\tCLEARED"

fclean: clean
	@$(DEL) $(NAME) ./libft.a ./libmlx.dylib
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)
	@tput setaf 33 && echo "\tLIBS\t\tCLEARED😁"

re: fclean all

leo :
	@tput setaf 88 && echo " _________      ___.          ________ ________   "
	@tput setaf 856 && echo '\_   ___ \ __ _\_ |__   ____ \_____  \\______ \  '
	@tput setaf 964 && echo '/    \  \/|  |  \ __ \_/ __ \  _(__  < |    |  \ '
	@tput setaf 964 && echo '\     \___|  |  / \_\ \  ___/ /       \|    `   \'
	@tput setaf 856 && echo ' \______  /____/|___  /\___  >______  /_______  /'
	@tput setaf 88 && echo '        \/          \/     \/       \/        \/ '

pallet :	
	@for i in `seq 1 1000` ; do \
	tput setaf $$i && echo "This is color $$i" ; \
	done
