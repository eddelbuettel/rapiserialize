\name{RApiSerialize-package}
\alias{RApiSerialize-package}
\alias{RApiSerialize}
\alias{serializeToRaw}
\alias{unserializeFromRaw}
\docType{package}
\title{
  R API for Serialization 
}
\description{
  This package provides other packages with access to the internal 
  R serialization code. Access is provided at the C function level via the
  registered function facility

  For convenience and testing purposes, two wrapper functions are also
  provided at the R level.
}
\usage{
  serializeToRaw(obj)
  unserializeFromRaw(obj)
}
\arguments{
  \item{obj}{An R object which is going to (un)serialized by the corresponding function.}
}
\details{
  The C code in this package is taken from R source code, where it
  provided for use by R only in a way that renders it inaccessible to
  other packages.

  This package aims to fill this gap by providing access to the same
  functionality, at the cost of making a copy.
}
\author{
  Dirk Eddelbuettel put together this package, based on earlier work by
  Junji Nakano and Ei-ji Nakama who also included the C code from R for
  serialization in their \pkg{Rhpc} package.  R Core wrote the
  underlying C code for use in R itself.

  The package is maintained by Dirk Eddelbuettel.
}
\keyword{package}
\seealso{
  The R source code in \code{src/main/serialize.c}.
}
\examples{
  ## calling the R wrapper 
  serializeToRaw(letters)
}
