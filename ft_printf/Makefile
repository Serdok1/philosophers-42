NAME		= libftprintf.a
LIBFT		= libft
SRC_DIR		= ./
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	ft_printf ft_printf_utils ft_printf_utils_long ft_printf_utils_two
BONUS_FILES =	ft_printf_bonus ft_printf_utils_bonus

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BNS			=	$(addsuffix .c, $(BONUS_FILES))
BNS_OBJ		=	$(addsuffix .o, $(BONUS_FILES))

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

bonus:
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(CC) $(CCFLAGS) -c $(BNS)
			@$(AR) $(NAME) $(BNS_OBJ)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@rm -fr $(BNS_OBJ)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(RED)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(RED)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

re_bonus:	fclean bonus
			@echo "kkkkkkkk"

.PHONY:		all clean fclean re norm re_bonus bonus