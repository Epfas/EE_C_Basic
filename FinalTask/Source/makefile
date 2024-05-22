CC=C:\MinGW\bin\gcc.exe
CFLAGS=-c -L -I
CFLAGS2=-c -L

all: data_reg.exe
	echo Deleting object files...
	del *.o
	data_reg.exe -f data.csv -g M 

data_reg.exe: epfas_date_time.o data_model.o app_argv_handler.o main.o
	$(CC) -o data_reg.exe main.o epfas_date_time.o app_argv_handler.o data_model.o

epfas_date_time.o: epfas_date_time.c
	$(CC) $(CFLAGS) -o epfas_date_time.o epfas_date_time.c

data_model.o: data_model.c
	$(CC) $(CFLAGS) -o data_model.o data_model.c

app_argv_handler.o: app_argv_handler.c
	$(CC) $(CFLAGS) -o app_argv_handler.o app_argv_handler.c

main.o: main.c 
	$(CC) $(CFLAGS) -o main.o main.c
