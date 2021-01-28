
library:
	#compile all .c++ files
	#since we are creating a library, do not link them
	#use std 20 and O3
	gdc ./Source/Abstraction/FluidEngineMember.c++ \
		./Source/Mathematics/Tensor.c++ \
		-c -O3 -std=c++2a 
	#remove the library--in case I delete a file later
	rm ./lib/fluidengine.a 
	#add all the .o files into the library
	ar crf ./lib/fluidengine.a ./FluidEngineMember.o --target=elf64-x86-64
	ar crf ./lib/fluidengine.a ./Tensor.o --target=elf64-x86-64
	#clean up
	rm *.o
	@echo done!
test:
	#compile in **everything**
	gdc ./Source/Abstraction/FluidEngineMember.c++ \
		./Source/Mathematics/Tensor.c++ \
		./Tests/BigBoiiMain.c++ \
		-O3 -std=c++2a
	@echo running...
	./a.out
