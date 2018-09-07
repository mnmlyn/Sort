file=Sort-main.cpp 001.BubbleSort.cpp 002.SelectSort.cpp 003.InsertSort.cpp 004.QuickSort.cpp 005.HeapSort.cpp 006.MergeSort.cpp
sort:$(file)
	g++ -g -o sort $(file)