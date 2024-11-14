LIBFT_PATH = libft

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

SRC = src/utils.c \

OBJ = $(SRC:%.c=%.o)

TESTS_DIR = tests

MANDATORY = isalpha \
			isdigit \
			isalnum \
			isascii \
			isprint \
			toupper \
			tolower \
			\
			strlen \
			strlcpy \
			strlcat \
			strchr \
			strrchr \
			strncmp \
			strnstr \
			strdup \
			substr \
			strjoin \
			strtrim \
			split \
			\
			bzero \
			memset \
			memcpy \
			memmove \
			memchr \
			memcmp \
			\
			atoi \
			calloc \

MANDATORY_OBJ = $(MANDATORY:%=$(TESTS_DIR)/ft_%.o)

BONUS = lstnew \

BONUS_OBJ = $(BONUS:%=$(TESTS_DIR)/ft_%.o)

CUSTOM = isinset \
		 isspace \

CUSTOM_OBJ = $(CUSTOM:%=$(TESTS_DIR)/ft_%.o)

INC = include $(LIBFT_PATH)

CFLAGS += -Wall -Wextra -Werror $(INC:%=-I%)

LDFLAGS = -L$(LIBFT_PATH)
LDLIBS = -lft

DEP = $(SRC:%.c=%.mk) $(MANDATORY_OBJ:%.o=%.mk) $(BONUS_OBJ:%.o=%.mk) $(CUSTOM_OBJ:%.o=%.mk)
COMPDB = $(DEP:%.mk=%.compdb.json)

CC ?= cc
RM ?= rm -f

.PHONY: all
all: mandatory bonus

.PHONY: mandatory
mandatory:
	@printf '\033[1;95m[ MANDATORY ]\033[0m\n'; \
	$(MAKE) --no-print-directory $(MANDATORY)

.PHONY: $(MANDATORY)
$(MANDATORY): %: $(TESTS_DIR)/ft_%.o $(OBJ) .libft_mandatory
	@$(CC) -o $@ $(filter-out .libft_mandatory,$^) $(LDFLAGS) $(LDLIBS) >/dev/null 2>&1; \
	if [ $$? -eq 0 ]; then \
		printf "\033[2;97mft_$@:\033[0m"; \
		./$@; \
		printf "\033[0m\n"; \
		$(RM) $@; \
	else \
		printf "\033[2;97mft_$@: \033[0;1;91m[DOES NOT COMPILE]\033[0m\n"; \
	fi

.PHONY: .libft_mandatory
.libft_mandatory:
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) all

.PHONY: bonus
bonus:
	@printf '\033[1;95m[ BONUS ]\033[0m\n'; \
	$(MAKE) --no-print-directory $(BONUS)

.PHONY: $(BONUS)
$(BONUS): %: $(TESTS_DIR)/ft_%.o $(OBJ) .libft_bonus
	@$(CC) -o $@ $(filter-out .libft_bonus,$^) $(LDFLAGS) $(LDLIBS) >/dev/null 2>&1; \
	if [ $$? -eq 0 ]; then \
		printf "\033[2;97mft_$@:\033[0m"; \
		./$@; \
		printf "\033[0m\n"; \
		$(RM) $@; \
	else \
		printf "\033[2;97mft_$@: \033[0;1;91m[DOES NOT COMPILE]\033[0m\n"; \
	fi

.PHONY: .libft_bonus
.libft_bonus:
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) bonus


.PHONY: custom
custom:
	@printf '\033[1;95m[ CUSTOM ]\033[0m\n'; \
	$(MAKE) --no-print-directory $(CUSTOM)

.PHONY: $(CUSTOM)
$(CUSTOM): %: $(TESTS_DIR)/ft_%.o $(OBJ) .libft_mandatory
	@$(CC) -o $@ $(filter-out .libft_mandatory,$^) $(LDFLAGS) $(LDLIBS) >/dev/null 2>&1; \
	if [ $$? -eq 0 ]; then \
		printf "\033[2;97mft_$@:\033[0m"; \
		./$@; \
		printf "\033[0m\n"; \
		$(RM) $@; \
	else \
		printf "\033[2;97mft_$@: \033[0;1;91m[DOES NOT COMPILE]\033[0m\n"; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

ifeq ($(filter fclean dclean deps,$(MAKECMDGOALS)),)
-include $(DEP)
endif

.PHONY: deps
deps: dclean $(DEP)

%.mk: %.c
	@$(CC) $(CFLAGS) -MF $@ -MM -MG -MP -MT '$*.o $@' $<

.PHONY: compdb
compdb: .compclean compile_commands.json

.PHONY: .compclean
.compclean:
	@$(RM) compile_commands.json
	@echo "Generating compile_commands.json"

compile_commands.json: $(COMPDB)
	@printf "[\n" > $@
	@sed -e 's/^}$$/},/' -e 's/^/  /' $(COMPDB) | sed -e '$$ s/},$$/}/' >> $@
	@printf "\n]" >> $@
	@$(RM) $(COMPDB)

%.compdb.json:
	@printf "{\n\
	  \"directory\": \"$(ROOT_DIR)\",\n\
	  \"file\": \"$*.c\",\n\
	  \"output\": \"$*.o\",\n\
	  \"command\": \"$(CC) $(CFLAGS) -o $*.o -c $<\"\n\
	}" > $@

.PHONY: clean
clean:
	@$(RM) $(OBJ) $(MANDATORY_OBJ) $(BONUS_OBJ)

.PHONY: dclean
dclean:
	@$(RM) $(DEP)

.PHONY: cclean
cclean:
	@$(RM) $(COMPDB)

.PHONY: fclean
fclean: clean cclean dclean
