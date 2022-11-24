all: main.exe

main.exe : 
	@g++ -Wall -Wextra -std=c++17 main.cpp -o main.exe

test :
	@make main.exe
	./main.exe two_sum_target_n_data.txt
	@make clean

clean : 
	@rm main.exe
