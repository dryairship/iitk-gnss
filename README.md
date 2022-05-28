## IITK - GNSS

### Build:

```
mkdir build
cd build
cmake ../src
make
```

### Run:
```
./iitk-gnss
```

### Options:

Two samples of acquisition algorithms have been provided.  
To choose between them, you need to specify the algorithm in the cmake command.

For algorithm 1: (default)
```
cmake ../src -DACQUISITION_ALGO=Algorithm1
```

For algorithm 2:
```
cmake ../src -DACQUISITION_ALGO=Algorithm2
```

After running the cmake command, run `make` again to build the project.
