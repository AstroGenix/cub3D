# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberehov <dberehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:58:57 by dberehov          #+#    #+#              #
#    Updated: 2024/10/17 23:31:54 by dberehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colours
GRAY	= \033[0;90m
RED		= \033[0;91m
GREEN	= \033[0;92m
YELLOW	= \033[0;93m
BLUE	= \033[0;94m
MAGENTA	= \033[0;95m
CYAN	= \033[0;96m
WHITE	= \033[0;97m

# Background Colours                                                                                                
BGRED		= \033[0;41m
BGREEN  	= \033[0;42m
BGYELLOW	= \033[0;43m
BGBLUE		= \033[0;44m
BGPURPLE	= \033[0;45m
BGCYAN		= \033[0;46m

# Reset Colour
RC	=	\033[0;39m

#Compiler and flags
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror -I

# Definitions
NAME	= libft.a
SRC_DIR	= sources/
OBJ_DIR = objects/

# Source Directories
CONVERSION_DIR		=	conversion/
FT_IS_DIR			=	ft_is/
FT_PRINTF_DIR		=	ft_printf/
GET_NEXT_LINE_DIR	=	get_next_line/
LIST_DIR			=	list/
MEM_DIR				=	mem/
PRINT_DIR			=	print/
STRING_DIR			=	string/

# Source Files
CONVERSION		=	ft_atoi ft_itoa ft_tolower ft_toupper
FT_IS			=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint
FT_PRINTF		=	ft_print_hexa ft_print_nums ft_print_pntr ft_print_text	  \
					ft_printf
GET_NEXT_LINE	=	get_next_line get_next_line_utils
LIST			=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone   \
					ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize
MEM				=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy		  \
					ft_memmove ft_memset
PRINT			=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd
STRING			=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin		  \
					ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp	  \
					ft_strnstr ft_strrchr ft_strtrim ft_substr

# Other
SRC_FILES		=	$(addprefix $(CONVERSION_DIR),$(CONVERSION))			  \
					$(addprefix $(FT_IS_DIR),$(FT_IS))						  \
					$(addprefix $(FT_PRINTF_DIR),$(FT_PRINTF))				  \
					$(addprefix $(GET_NEXT_LINE_DIR),$(GET_NEXT_LINE))		  \
					$(addprefix $(LIST_DIR),$(LIST))						  \
					$(addprefix $(MEM_DIR),$(MEM))							  \
					$(addprefix $(PRINT_DIR),$(PRINT))						  \
					$(addprefix $(STRING_DIR),$(STRING))					  \
				
SRCS			=	$(addprefix $(SRC_DIR),$(addsuffix .c, $(SRC_FILES)))
OBJS			=	$(addprefix $(OBJ_DIR),$(addsuffix .o, $(SRC_FILES)))
OBJ_FILES		=	.cache_exists

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(BGBLUE)              Libft compiled             $(RC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(CONVERSION_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_IS_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_PRINTF_DIR)
	@mkdir -p $(OBJ_DIR)$(GET_NEXT_LINE_DIR)
	@mkdir -p $(OBJ_DIR)$(LIST_DIR)
	@mkdir -p $(OBJ_DIR)$(MEM_DIR)
	@mkdir -p $(OBJ_DIR)$(PRINT_DIR)
	@mkdir -p $(OBJ_DIR)$(STRING_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
#	@echo "$(BGREEN)       Compiling needed files        $(RC)"
	@echo "$(GREEN) -> Compiled: $(RC) $<"
	@$(CC) $(CFLAGS) ../includes -c $< -o $@

clean: 
	@echo "$(RED) -> Removed: $(RC) objects folder $<"
	@rm -fr $(OBJ_DIR)
	@echo "$(BGPURPLE)        Libft object files deleted       $(RC)"

fclean: clean
	@echo "$(RED) -> Removed: $(RC) libft.a"
	@echo "$(BGPURPLE)        Libft executable deleted         $(RC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re