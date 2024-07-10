# $@: name of the target file (one before colon)
# $<: name of first prerequisite file (first one after colon)
# $^: names of all prerequisite files (space separated)
# $*: stem (bit which matches the % wildcard in rule definition)
#
# VAR = val: Normal setting - values within are recursively expand when var used.
# VAR := val: Setting of var with simple expansion of values inside - values are expanded at decl time.
# VAR ?= val: Set var only if it doesn't have a value.
# VAR += val: Append val to existing value (or set if var didn't exist).

# Program name and output directory
OUTPUT_DIR = 			.
NAME = 					$(OUTPUT_DIR)/philo

# Other directories
SOURCES_DIR =			srcs
INCLUDES_DIR =			incl
OBJECTS_DIR :=			objs

# Files
# HEADERS =				$(wildcard $(INCLUDES_DIR)/*.h)
HEADERS =				incl/philo.h
# SOURCES =				$(wildcard $(SOURCES_DIR)/*.c)
SOURCES =				$(wildcard $(SOURCES_DIR)/*.c)
OBJECTS =				$(patsubst $(SOURCES_DIR)/%.c, $(OBJECTS_DIR)/%.o,$(SOURCES))

#libraries
# LIBFT_DIR =				libs/libft
# LIBFT_INCLUDES_DIR =	$(LIBFT_DIR)/incl
# LIBFT =					$(LIBFT_DIR)/libft.a
# LIBFT_LL_FLAGS +=		-lft

# BONUS_SOURCES = \
# 	$(wildcard $(BONUS_DIR)/*.c)
# BONUS_OBJECTS = 	$(BONUS_SOURCES:.c=.o)
# BONUS_OBJECTS += 	$(OBJECTS)

# Compiler and options
CC = 			cc
CFLAGS += 		-Wall -Wextra -Werror
UI_FLAGS +=		-I$(INCLUDES_DIR) # -I$(LIBFT_INCLUDES_DIR)
# UL_FLAGS := 	-L$(LIBFT_DIR)
# LL_FLAGS := 	$(LIBFT_LL_FLAGS)
DEBUG_FLAGS :=	-fsanitize=thread

# Phony Targets
.PHONY: all clean fclean re
.PHONY: libft bonus
.PHONY: aclean ac rec ar
.PHONY: norm

# Link Targets
all: $(NAME)
$(NAME): $(OBJECTS) | $(HEADERS)
	@echo "--------------------------------"
	@echo "make OBJECTS done.\n"
	$(CC) $(UI_FLAGS) $(UL_FLAGS) $^ $(LL_FLAGS) -o $@ $(DEBUG_FLAGS)
	@echo "--------------------------------"
	@echo "make $(NAME) done.\n"
	chmod 777 $(NAME)
	@echo "--------------------------------"
	@echo "change permission of $(NAME) done.\n"

# Compile Targets
$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c | $(OBJECTS_DIR) $(HEADERS)
	$(CC) $(W3_FLAGS) $(UI_FLAGS) -c $< -o $@ $(DEBUG_FLAGS)
$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

# Clean Targets
clean:
	rm -f $(OBJECTS)
	rm -fd $(OBJECTS_DIR)
#	 make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
#	make -C $(LIBFT_DIR) clean
re: fclean all

# libft
libft: $(LIBFT)
$(LIBFT):
	@echo "Compiling libft library..."
	make -C $(LIBFT_DIR)
	@echo "----------------"
	@echo "make libft done.\n"

# # bonus
# bonus: all $(BONUS_OBJECTS)
# 	ar rcs $(NAME) $(BONUS_OBJECTS)

# non mandatory
aclean: all clean
ac: all clean
rec: re clean
ar:
	ar rcs $(OUTPUT_DIR)/$(NAME) $(OBJECTS)

norm:
	norminette $(SRCS) $(INCL)
