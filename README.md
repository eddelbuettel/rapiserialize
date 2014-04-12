## RApiSerialize

This package provides C-level serialization as R does for itself. It is
useful if you are writing C (or C++) code in an R package which needs to
(un)serialize R data structures, and wants to do it faster than calling the
corresponding R level function would do.  

In other words, this is somewhat specialised for situation of high data
throughput, or other cases of a need for high performance.  Or maybe you are
just impatient and want the result faster.

This package owes a lot of debt to the
[Rhpc](http://cran.rstudio.com/package=Rhpc) package by 
Junji Nakano and Ei-ji Nakama. It gave me the idea of using a copy of the
code which is not exported by R itself.  And of course credit is due to the R
Core team for writing R, and the code used here.

## Copyrights

Copyright (C) 2014         Dirk Eddelbuettel 
Copyright (C) 2013 - 2014  Junji Nakano and Ei-ji Nakama
Copyright (C) 1995 - 2013  The R Core Team

## Example use

See my [RcppRedis](https://github.com/eddelbuettel/rcppredis) package for use
of this package

## Status

[![Build Status](https://travis-ci.org/eddelbuettel/rapiserialize.png)](https://travis-ci.org/eddelbuettel/rapiserialize)
