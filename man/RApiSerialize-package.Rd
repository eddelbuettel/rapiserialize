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
  serializeToRaw(obj, version=2)
  unserializeFromRaw(obj)
}
\arguments{
  \item{obj}{An R object which is going to (un)serialized by the corresponding function.}
  \item{version}{An integer selection the R serialization format. Default is 2, and values 2 or 3 are currently supported.}
}
\details{
  The C code in this package is taken from R source code, where it
  provided for use by R only in a way that renders it inaccessible to
  other packages.

  This package aims to fill this gap by providing access to the same
  functionality, at the cost of making a copy.

  To use the serialization and deserialization code provided here, a
  client package simply adds \code{LinkingTo: RApiSerialize} in its
  \code{DESCRIPTION} file and includes the header file
  \code{RApiSerializeAPI.h}.
}
\author{
  Dirk Eddelbuettel put together this package, based on earlier work by
  Ei-ji Nakama and Junji Nakano who also included the C code from R for
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
