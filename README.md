## A simple Monte Carlo Simulation of proton-proton collision using pythia


## Compile

```
g++ -I/path/to/pythia8/include code.cc -o nameit -lpythia8 -L /path/to/pythia8/lib 

```
# Don't forget to export the pythia lib dir into the path env.

```
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/path/to/pythia8/lib
```

# Include ROOT
To use Pythia along with ROOT add the following flags
```
  `root-config --cflags` ... `root-config --glibs`
```

first one after include -I, and second one after libs -L


# Optional:

You can create a Makefile to complile all your source files using make


### Install Pythia8
<a href="https://pythia.org">Pythia8</a>



@Aelabass ya

<h3>All <em><strong>good-yoi</strong></em></h3>
