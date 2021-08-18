# Building the documentation
## PDF
If you don't want to use the pre-built pdf, you need latex and gnuplot, as well as some shell scripting utilities.
### Linux
#### Dependencies
- texlive-most
- lualatex
- gnuplot
- grep
- sed
- tee
- bash
#### Building
Run `make` on the root directoy to compile the `algo-bench`:

``` sh
$ cd algo-bench
$ make
```
The, hope on to the `script` subfolder and run the `bench` script:

``` sh
$ cd script
$ ./bench
```

Next, hop on to the `doc` subdirectory make the gnuplot graph with the resulting `.dat` files from `bench`:

``` sh
$ gnuplot
gnuplot> set xrange [0:200]
gnuplot> set terminal png size 800,600
gnuplot> set output "graph.png"
gnuplot> plot x , x*log(x) , "insertion.dat", "quick.dat"
gnuplot> replot
```

Finally, compile the latex document into a pdf files with the help of `lualatex`:

``` sh
$ lualatex --shel-escape paper 
```

You're done! The pdf is now built and ready to be read.

### Windows
I don't know much about linux, but might not be that different on the latex side. The scripting part of the build, however, would need to be completely rebuilt for windows in `bat` format, for example.
