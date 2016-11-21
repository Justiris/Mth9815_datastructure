For Exercise1:
to compile:

g++ Exercise1_1.cpp -o Exercise1_1.exe -lrt

g++ Exercise1_2.cpp -o Exercise1_2.exe -lrt



to run:

./Exercise1_1.exe

./Exercise1_2.exe

For Exercise2 and Exercise3:
to compile:
g++ test_products.cpp -o test_products.exe -std=c++11

to run:
./test_products.exe

The program has been testes both in Ubuntu gcc and Windows Mingw 5.3.0
However, in Mingw 5.3.0, please use g++ Exercise1_1.cpp -o Exercise1_1.exe -I <directory> to inlcude boost library