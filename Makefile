all:
		clang -g --Wall -Wextra -Werror -D BUFFER_SIZE=1000 *.c -I *.h