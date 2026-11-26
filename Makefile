CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

all: Lab_10_2_A UnitTest_10_2_A

Lab_10_2_A: Lab_10_2_A.cpp io.cpp sort_search.cpp student.h io.h sort_search.h
	$(CXX) $(CXXFLAGS) Lab_10_2_A.cpp io.cpp sort_search.cpp -o $@

UnitTest_10_2_A: UnitTest_10_2_A.cpp sort_search.cpp student.h sort_search.h doctest.h
	$(CXX) $(CXXFLAGS) UnitTest_10_2_A.cpp sort_search.cpp -o $@

check: UnitTest_10_2_A
	./UnitTest_10_2_A

clean:
	rm -rf Lab_10_2_A UnitTest_10_2_A *.dSYM
