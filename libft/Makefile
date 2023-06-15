#################### INCLUDE ####################

-include make/includes.mk
-include make/sources.mk

INCPATH		:=	includes/
INC			:=	-I $(INCPATH)

################# FOLDER PATHS ##################

OBJFLDR		:=	.objects/

#################### SOURCES ####################

OBJS		:=	$(SOURCES:.c=.o)
OBJS		:=	$(addprefix $(OBJFLDR), $(OBJS))

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror -g

MAKELIB		:=	ar -rcs

DEL			:=	rm -rf

NAME		:=	libft.a
NAMEEXEC	:=	prog

MAIN		:=  main_*

####################  RULES  ####################

${NAME}: ${OBJFLDR} ${OBJS} $(INCLUDES)
		${MAKELIB} ${NAME} ${OBJS}
		ranlib ${NAME}
		@echo "Library libft created"

all:	${NAME}

.objects/%.o:	%.c
		mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ ${INC}

${OBJFLDR}:
		mkdir -p ${OBJFLDR}

clean:
		${DEL} ${OBJFLDR}

fclean: clean
		${DEL} ${NAME}

re:		fclean all

gmk:
		@if [ -d make ];then echo ok;else mkdir make;fi
		@find -name '*.c' | sed 's/^/SOURCES += /' > make/sources.mk
		@find -name '*.h' | sed 's/^/INCLUDES += /' > make/includes.mk

test: $(NAME)
	$(CC) $(CFLAGS) -g $(MAIN) -o $(NAMEEXEC) -L . -lft


.PHONY: all clean fclean re%
