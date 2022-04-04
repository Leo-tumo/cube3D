NAME 		= cub3D
HEADER 		= cub3d.h
LIBFT_DIR 	= libs/libft/
LIBFT 		= $(LIBFT_DIR)libft.a
LIBMLX_DIR 	= libs/minilibx_mms/
LIBMLX 		= $(LIBMLX_DIR)libmlx.dylib
MAKE 		= make
CLEAN 		= clean
FCLEAN 		= fclean

SRC 		= main.c\
			parser/parser.c\
			parser/parser_map.c\
			parser/error_utils_one.c\
			parser/error_utils_two.c\
			utils/get_inf_utils.c\
			utils/minor_utils.c\
			utils/key_hook_utils_one.c\
			utils/sprite_utils.c\
			utils/screenshot.c\
			utils/cub3d_utils_one.c\
			utils/cub3d_utils_two.c
OBJ 		= $(SRC:.c=.o)
CC 			= gcc
FLAG 		= -Wall -Werror -Wextra -g -O0
FLAGMLX 	= -framework OpenGL -framework AppKit
OPTION 		= -c -D GL_SILENCE_DEPRECATION
OPTIONOBJ 	= -o
DEL 		= rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	@cd $(LIBFT_DIR) && mv ./libft.a ../../
	@cd $(LIBMLX_DIR) && mv ./libmlx.dylib ../../
	@$(CC) $(FLAG) $(OBJ) -L. -lmlx -lft $(FLAGSMLX) $(OPTIONOBJ) $(NAME)

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)
	
$(LIBMLX):
	@cd $(LIBMLX_DIR) && $(MAKE)

%.o: %.c
	@$(CC) $(FLAG) $(OPTION) $< $(OPTIONOBJ) $@

.PHONY: all clean fclean re

clean:
	@$(DEL) $(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)
	@cd $(LIBMLX_DIR) && $(MAKE) $(CLEAN)
	@cd parser && $(DEL) *.o
	@cd utils && $(DEL) *.o
	@$(DEL) *.o

fclean: clean
	@$(DEL) $(NAME) ./libft.a ./libmlx.dylib
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)

re: fclean all
