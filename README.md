# Teseo2: Turn the Eldest Seismograms into the Electronic Original Ones

Teseo2 is a software tool for quick and accurate digitization/vectorization of seismogram traces from raster files.

It has been developed in the framework of the Sismos project [Michelini and the Sismos Team, 2005] at Istituto Nazionale di Geofisica e Vulcanologia (Italy). This name was inspired by the myth of Theseus and it is also an acronym for 

**T**urn the **E**ldest **S**eismograms into the **E**lectronic **O**riginal **O**nes.

Teseo2 is a plug-in for [GIMP](https://www.gimp.org/) - *GNU Image Manipulation Program* - that extends its functionalities for seismological studies. The GIMP is a multiplatform photo manipulation tool freely distributed. It works on many operating systems, in many languages.

Teseo2 allows primarily for:

  - additional operations on the vectorized trace (i.e. resampling and alignment)
  - supervised vectorization algorithms (colour weighted mean)
  - analysis after trace vectorization, such as curvature correction and time realignment
  - trace import/export in several formats (such as SAC, SVG, DXF, ASCII, Timemarks distances).

In order to keep track of the stages and parameters of a seismogram vectorization, Teseo2 is able to write this information into the image saved into GIMP's native [XCF](https://fileinfo.com/extension/xcf) file type.

Teseo2 is developed following the "Open-Source" philosophy and it is freely distributed under GPL license. It is cross-platform and the sources, the binaries for Linux, Windows and Mac OS X, are periodically updated on the Sismos web site.

- Website: [http://teseo.rm.ingv.it/](http://teseo.rm.ingv.it/)
- Developer e-mail: *teseo [at] ingv.it*
- User mailing list: *teseo-user [at] yahoogroups.com*
- Mailing list archive: [http://groups.yahoo.com/group/teseo-user/](http://groups.yahoo.com/group/teseo-user/)
- GIMP: [https://www.gimp.org/](https://www.gimp.org/)

### Documentation links
  - Teseo User Manual: [http://teseo.rm.ingv.it/docs/en/](http://teseo.rm.ingv.it/docs/en/)
  - Teseo and Seismogram Digitization Workflow: [http://teseo.rm.ingv.it/docs/posters/poster_ssa.pdf](http://teseo.rm.ingv.it/docs/posters/poster_ssa.pdf)
  - Teseo for Dummies: [http://teseo.rm.ingv.it/pub/teseo/doc/teseo2_for_dummies.pdf](http://teseo.rm.ingv.it/pub/teseo/doc/teseo2_for_dummies.pdf)

### Using Teseo by Docker (recommended)

We recommend to run Teseo by Docker in a Unix-like environment (Linux or Mac OS X).

#### Installation and use Teseo by Docker

##### Requirements

  - **Docker** (Linux, Mac OS X, Windows)
    - [https://docs.docker.com/install/](https://docs.docker.com/install/)
  - **X11 server**
    - Mac OS X: Xquartz - [https://www.xquartz.org/](https://www.xquartz.org/)
  - **git**
    - Mac OS X: Xcode - `xcode-select --install`
  - **make**
    - Mac OS X: Xcode - `xcode-select --install`


##### Download teseo2 repository
 
```
git clone https://github.com/INGV/teseo2.git
cd teseo2
```

##### Build Docker Image

```
make -f DockerMakefile build
```

##### Run Docker Image

Teseo Docker Image is based on X11 environment.

You can run Teseo Docker Image by one of the following option:

1) Using X11 local socket. It works on Linux but it does not work on Mac OS X.

```
make -f DockerMakefile run_xlocal
```

2) Based on *xhost*.

It is not possible running in this mode when you are offline.

You need to set up a X11 server and enable *xhost* for your local IP or for connecting from any client running:

```
xhost +
``` 
  
```
make -f DockerMakefile run_xhost
```

*Note for Mac OS X*: in *Xquartz* Preferences, within *"Security"* tab, you have to check the option *"Allow connections from network clients"*.

##### Update Docker Image

To update your Teseo Docker Image pull the changes from `git` repository and rebuild by `make`.

```
cd teseo2
git pull
```

Rebuild

```
make -f DockerMakefile build
```


### General Build from scratch

#### Requirements

  - gimp-2.2.9 up to gimp-2.8.x

The configure scripts might fail asking you the dependency libraries you have to install or to specify into PKG\_CONFIG\_PATH.

#### Quick installation

```
$ tar xzvf teseo*.tar.gz
$ cd teseo2/
$ cd gtk-addons
$ ./configure && make && sudo make install
$ cd ../newuoa
$ ./configure F77=<fortran-path> && make && sudo make install
$ cd ../teseo-2
$ ./configure && make && sudo make install
```

Details in file ./teseo-2/INSTALL


### Authors

Stefano Pintore and Matteo Quintiliani.

### Contributors

Diego Franceschi, Antoine Schlupp, Daniel Amorese.

### References

Michelini, A. and the Sismos Team (2005). *Collection, digitization and distribution of historical seismological data at INGV.* EOS, 86(28). 

Pintore S., Quintiliani M., Franceschi D. (2005) *Teseo: a vectoriser of historical seismograms.* Computers & Geosciences, Volume 31, Issue 10, 2005, Pages 1277-1285, ISSN 0098-3004, [http://dx.doi.org/10.1016/j.cageo.2005.04.001](http://dx.doi.org/10.1016/j.cageo.2005.04.001)

Schlupp, Antoine & Cisternas, Armando. (2007). **Source history of the 1905 great Mongolian earthquakes (Tsetserleg, Bolnay).** Geophysical Journal International. 169. 1115 - 1131. 10.1111/j.1365-246X.2007.03323.x. 

Cadek, O. (1987). *Studying earthquake ground motion in prague from wiechert seismograph records.* Gerl. Beitr. Geoph., 96:438-447.