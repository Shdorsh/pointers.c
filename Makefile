SRC = pointer.c
OBJS = $(SRC:.c = .o)
CC = gcc
CFLAGS = -Wextra -Wall -Werror
TARGETNAME = pointer

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

a: $(OBJS)
	ar rcs $(TARGETNAME).a $^

so: $(OBJS)
	$(CC) $(CFLAGS) -shared -fPIC $(OBJS) -o $(TARGETNAME).so

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(TARGETNAME).a $(TARGETNAME).so

.PHONY: a so clean fclean