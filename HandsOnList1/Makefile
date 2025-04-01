CC = cc
CFLAGS = -Wall
OUTDIR = bin

# Ensure the output directory exists
$(OUTDIR):
	mkdir -p $(OUTDIR)

# Define file groups
GROUP1 = 1a.c 1b.c 1c.c 2.c 3.c 4.c 5.c 6.c 7.c 8.c 9.c 10.c 11.c 12.c 13.c 14.c 15.c
GROUP2 = 16a.c 16b.c 17a.c 17b.c 18a.c 18b.c
GROUP3 = 19.c 20.c 21.c 22.c 23.c 24.c
GROUP4 = 25a.c 25b.c
GROUP5 = 26.c 27.c 28.c 29.c 30.c

# Compile all
all: $(OUTDIR) group1 group2 group3 group4 group5

# Compilation rules for each group
group1: $(patsubst %.c, $(OUTDIR)/%.out, $(GROUP1))
group2: $(patsubst %.c, $(OUTDIR)/%.out, $(GROUP2))
group3: $(patsubst %.c, $(OUTDIR)/%.out, $(GROUP3))
group4: $(patsubst %.c, $(OUTDIR)/%.out, $(GROUP4))
group5: $(patsubst %.c, $(OUTDIR)/%.out, $(GROUP5))

# Generic rule to compile .c files into .out files
$(OUTDIR)/%.out: %.c | $(OUTDIR)
	$(CC) $(CFLAGS) $< -o $@

# Clean compiled files
clean:
	rm -rf $(OUTDIR)/*.out
