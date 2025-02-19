NAME=executable

FILES:=Fixed/Fixed.cpp elements/Dot.cpp elements/Line.cpp elements/Vector2D.cpp
FILES:=$(addprefix src/, $(FILES))
OBJS:=$(FILES:%.cpp=%.o)
TEST_FILES:= asserts.cpp unit/example.cpp unit/elements/Dot.cpp unit/elements/Line.cpp \
			 unit/elements/Vector2D.cpp
TEST_FILES:=$(addprefix tests/, $(TEST_FILES))
TEST_OBJS:=$(TEST_FILES:%.cpp=%.o)
INCLUDES=-I includes/
COMPILER=c++

all: $(NAME)

$(NAME): $(OBJS) src/main.cpp
	$(COMPILER) $(INCLUDES) $(OBJS) src/main.cpp -o $(NAME)

%.o:%.cpp
	$(COMPILER) $(INCLUDES) -c $< -o $@

unit: $(TEST_OBJS) $(OBJS) tests/main.cpp
	@$(COMPILER) $(INCLUDES) -I tests/ $(OBJS) $(TEST_OBJS) tests/main.cpp -o unit
	@./unit
	@rm -rf unit

e2e: $(NAME)
	@./tests/e2e/Program.sh $(realpath $(NAME))

clean:
	@rm -rf $(OBJS) $(TEST_OBJS)

fclean: clean
	@rm -rf $(NAME) 

re: fclean all
