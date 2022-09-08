tut1%: tut1%.cc
	g++ -I/home/aelabass/Documents/PYTHIA8/pythia8307/include $@.cc -o $@ -lpythia8 -L/home/aelabass/Documents/PYTHIA8/pythia8307/lib

